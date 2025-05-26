/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:51:23 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 10:53:32 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_new_env_export(t_env **env, char *key)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup(key);
	new->value = NULL;
	new->full_str = ft_strdup(key);
	new->next = NULL;
	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	add_env_to_end(*env, new);
}

void	handle_export_token(t_token *current, t_env **envp)
{
	char	*equal_pos;
	int		key_len;
	char	*key;
	char	*value;

	equal_pos = ft_strchr(current->str, '=');
	if (!equal_pos)
	{
		if (!get_env_value(*envp, current->str))
			add_new_env_export(envp, current->str);
	}
	else
	{
		key_len = equal_pos - current->str;
		key = ft_substr(current->str, 0, key_len);
		value = ft_strdup(equal_pos + 1);
		set_env_value(envp, key, value);
		free(key);
		free(value);
	}
}

static void	print_export(t_env **envp)
{
	t_env	*cur;

	cur = *envp;
	while (cur)
	{
		printf("declare -x %s\n", cur->full_str);
		cur = cur->next;
	}
}

void	exec_export(t_all *all, t_tree *tree, t_env **envp)
{
	t_token		*current;

	if (tree->token->next)
	{
		current = tree->token->next;
		while (current)
		{
			handle_export_token(current, envp);
			current = current->next;
		}
	}
	else
	{
		print_export(envp);
	}
	all->exit_status = 0;
}
