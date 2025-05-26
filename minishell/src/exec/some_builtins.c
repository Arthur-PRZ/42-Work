/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:13:28 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/12 15:41:37 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_path(t_env *envp, char *str)
{
	char	*res;

	res = get_env_value(envp, str);
	if (!res)
	{
		printf("cd: %s not set\n", str);
		return (1);
	}
	return (0);
}

void	exec_env(t_all *all, t_env *envp)
{
	t_env	*current;
	char	*equal_pos;

	current = envp;
	while (current)
	{
		equal_pos = ft_strchr(current->full_str, '=');
		if (!equal_pos)
		{
			current = current->next;
			continue ;
		}
		printf("%s\n", current->full_str);
		current = current->next;
	}
	all->exit_status = 0;
}

void	exec_echo(t_all *all, t_tree *tree, int *exit_status)
{
	t_token	*current;
	bool	bool_flag;

	bool_flag = false;
	(void)exit_status;
	if (tree->token->next)
		current = tree->token->next;
	else
		return ((void)ft_putstr_fd("\n", 1));
	if (has_flag(&current))
	{
		bool_flag = true;
		if (current && current->str[0] == '\0')
			return ;
	}
	while (current)
	{
		ft_putstr_fd(current->str, 1);
		if (current->str[0] != '\0' && current->next)
			ft_putstr_fd(" ", 1);
		current = current->next;
	}
	if (bool_flag == false)
		ft_putstr_fd("\n", 1);
	all->exit_status = 0;
}

void	exec_pwd(t_all *all, int *exit_status)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		*exit_status = 142;
		return ;
	}
	printf("%s\n", cwd);
	free(cwd);
	all->exit_status = 0;
}

void	do_cmd(t_tree *tree, int *exit_status, t_env *envp, t_all *all)
{
	char	*cmd_path;

	cmd_path = get_cmd_path(tree->token->str, envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error : CMD not found\n", 2);
		*exit_status = 2;
		return ;
	}
	exec_cmd(cmd_path, tree->token, envp, all);
	free(cmd_path);
}
