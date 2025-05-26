/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:38:28 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/12 18:43:57 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	child_heredoc(t_tree *tree, t_all *all, int pipefd[2])
{
	signal(SIGQUIT, SIG_IGN);
	if (isatty(STDIN_FILENO))
		disable_echoctl();
	close(pipefd[0]);
	read_heredoc_loop(tree->right->token->str, pipefd, all);
	close(STDOUT_FILENO);
	close(pipefd[1]);
	free_all(all);
	exit(0);
}

static void	parent_heredoc(pid_t pid, t_tree *tree, t_all *all, int pipefd[2])
{
	int	status;

	signal(SIGINT, SIG_IGN);
	close(pipefd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		all->exit_status = 130;
	tree->heredoc_fd = pipefd[0];
	if (isatty(STDIN_FILENO))
		enable_echoctl();
	signal(SIGINT, sigint_handler_prompt);
	signal(SIGQUIT, sigquit_handler);
}

void	handle_heredoc(t_tree *tree, t_all *all)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return ;
	pid = fork();
	signal(SIGINT, signal_heredoc_setup);
	if (pid == 0)
		child_heredoc(tree, all, pipefd);
	else
		parent_heredoc(pid, tree, all, pipefd);
}

void	prepare_all_heredocs(t_tree *tree, t_all *all)
{
	if (!tree)
		return ;
	if (tree->token->arg_type == HEREDOC)
		handle_heredoc(tree, all);
	prepare_all_heredocs(tree->left, all);
	prepare_all_heredocs(tree->right, all);
}
