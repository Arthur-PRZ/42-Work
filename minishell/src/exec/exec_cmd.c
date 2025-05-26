/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:34:06 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/07 11:36:09 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handlechexec(char *cmd_path, t_token *token, t_env *envp, t_all *all)
{
	char	**args;
	char	**envc;
	int		exit_status;

	reset_signals_for_child();
	args = create_args(token);
	envc = create_tab(envp);
	exit_status = 0;
	if (execve(cmd_path, args, envc) == -1)
		exit_status = 2;
	free_tab(args);
	free_tab(envc);
	free_all(all);
	exit(exit_status);
}

void	handle_parent_waiting(pid_t pid, t_all *all)
{
	int	signal_num;

	waitpid(pid, &all->status, 0);
	if ((all->status & 0x7F) != 0)
	{
		signal_num = all->status & 0xFF;
		if (signal_num == SIGINT)
			all->exit_status = 130;
		else if (signal_num == SIGQUIT)
			all->exit_status = 131;
		else
			all->exit_status = 128 + signal_num;
	}
	else
		all->exit_status = (all->status >> 8) & 0xFF;
}

void	exec_cmd(char *cmd_path, t_token *token, t_env *envp, t_all *all)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		handlechexec(cmd_path, token, envp, all);
	else
		handle_parent_waiting(pid, all);
}
