/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:28:38 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/12 18:05:54 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_path_bis(t_env *envp, char *str)
{
	char	*res;

	res = get_env_value(envp, str);
	if (!res)
	{
		return (1);
	}
	return (0);
}

void	exec_cd(t_all *all, t_tree *tree, int *exit_status, t_env *envp)
{
	char	*oldpwd;
	char	*pwd;

	if (!tree->token->next && !check_path(envp, "HOME"))
		chdir(get_env_value(envp, "HOME"));
	oldpwd = getcwd(NULL, 0);
	if (tree->token->next && chdir(tree->token->next->str)
		&& !check_path_bis(envp, "OLDPWD"))
	{
		printf("cd: no such file or directory: %s\n", tree->token->next->str);
		*exit_status = 1;
		return ((void)free(oldpwd));
	}
	pwd = getcwd(NULL, 0);
	set_env_value(&envp, "PWD", pwd);
	set_env_value(&envp, "OLDPWD", oldpwd);
	(free(pwd), free(oldpwd));
	all->exit_status = 0;
}
