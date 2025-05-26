/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:31:50 by artperez          #+#    #+#             */
/*   Updated: 2025/05/12 16:14:15 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	disable_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	enable_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	child_append_redir(t_tree *tree, t_all *all,
	int *exit_status, t_env *envp)
{
	int	fd;
	int	exit_holder;

	exit_holder = *exit_status;
	fd = open(tree->right->token->str,
			O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		printf("Error: cannot open file\n");
		free_all(all);
		exit(exit_holder);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec(tree->left, exit_status, all, envp);
	free_all(all);
	exit(exit_holder);
}

void	exec_append_mode(t_tree *tree, int *exit_status,
	t_all *all, t_env *envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		child_append_redir(tree, all, exit_status, envp);
	waitpid(pid, &all->status, 0);
	if ((all->status & 0x7F) == 0)
		*exit_status = (all->status >> 8) & 0xFF;
}
