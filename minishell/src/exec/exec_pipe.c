/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:40:00 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/07 11:35:01 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	chp1(t_tree *tree, t_all *all, t_env *envp, int *pipefd)
{
	signal(SIGPIPE, SIG_IGN);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec(tree->left, &all->exit_status, all, envp);
	free_all(all);
	exit(1);
}

static void	chp2(t_tree *tree, t_all *all, t_env *envp, int *pipefd)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	exec(tree->right, &all->exit_status, all, envp);
	free_all(all);
	exit(1);
}

void	exec_pipe(t_tree *tree, t_all *all, t_env *envp)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		chp1(tree, all, envp, pipefd);
	waitpid(pid, NULL, 0);
	pid2 = fork();
	if (pid2 == -1)
		return ;
	if (pid2 == 0)
		chp2(tree, all, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid2, NULL, 0);
}
