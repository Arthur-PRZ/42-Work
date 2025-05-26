/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:07:52 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 11:11:40 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_valid_n_flag(const char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' || str[1] != 'n')
		return (false);
	while (str[i] == 'n' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

bool	has_flag(t_token **token)
{
	int	i;

	i = 0;
	if (is_valid_n_flag((*token)->str))
	{
		*token = (*token)->next;
		if (!(*token) || !is_valid_n_flag((*token)->str))
			return (true);
	}
	while ((*token) && is_valid_n_flag((*token)->str))
	{
		*token = (*token)->next;
		if (!(*token) || !is_valid_n_flag((*token)->str))
			return (true);
	}
	return (false);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*get_full_str(char *key, char *value)
{
	char	*temp;
	char	*res;

	temp = ft_strjoin(key, "=");
	res = ft_strjoin(temp, value);
	free(temp);
	return (res);
}

void	which_builtin(t_tree *tree, int *exit_status, t_all *all, t_env *envp)
{
	if (ft_strncmp(tree->token->str, "echo", 6) == 0)
		exec_echo(all, tree, exit_status);
	else if (ft_strncmp(tree->token->str, "cd", 3) == 0)
		exec_cd(all, tree, exit_status, envp);
	else if (ft_strncmp(tree->token->str, "pwd", 4) == 0)
		exec_pwd(all, exit_status);
	else if (ft_strncmp(tree->token->str, "export", 7) == 0)
		exec_export(all, tree, &envp);
	else if (ft_strncmp(tree->token->str, "unset", 6) == 0)
		exec_unset(all, tree, &envp);
	else if (ft_strncmp(tree->token->str, "env", 4) == 0)
		exec_env(all, envp);
	else if (ft_strncmp(tree->token->str, "exit", 5) == 0)
		exec_exit(exit_status, all);
}
