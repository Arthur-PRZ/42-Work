/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:44:34 by artperez          #+#    #+#             */
/*   Updated: 2025/05/06 12:48:31 by ctravers42       ###   ########.fr       */
/*   Updated: 2025/05/06 12:34:52 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	child_redir_output(t_tree *tree, t_all *all,
	int *exit_status, t_env *envp)
{
	int	fd;
	int	exit_holder;

	exit_holder = *exit_status;
	fd = open(tree->right->token->str,
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error: fd error\n");
		free_all(all);
		exit(exit_holder);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec(tree->left, exit_status, all, envp);
	free_all(all);
	exit(exit_holder);
}

void	exec_output_redirection(t_tree *tree, int *exit_status,
	t_all *all, t_env *envp)
{
	pid_t	pid;
	int		fd;
	int		exit_holder;

	fd = 0;
	pid = fork();
	exit_holder = *exit_status;
	if (pid == -1)
		return ;
	if (pid == 0)
		child_redir_output(tree, all, exit_status, envp);
	waitpid(pid, &all->status, 0);
	if ((all->status & 0x7F) == 0)
		*exit_status = (all->status >> 8) & 0xFF;
}

static void	child_input_redir(t_tree *tree, t_all *all,
	int *exit_status, t_env *envp)
{
	int	fd;
	int	exit_holder;

	exit_holder = *exit_status;
	fd = open(tree->right->token->str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: No such file or directory\n");
		free_all(all);
		exit(exit_holder);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	exec(tree->left, exit_status, all, envp);
	free_all(all);
	exit(exit_holder);
}

void	exec_input_redirection(t_tree *tree, int *exit_status,
	t_all *all, t_env *envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		child_input_redir(tree, all, exit_status, envp);
	waitpid(pid, &all->status, 0);
	if ((all->status & 0x7F) == 0)
		*exit_status = (all->status >> 8) & 0xFF;
}
