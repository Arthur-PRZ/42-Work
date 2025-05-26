/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:54:26 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 10:55:32 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_env_variable(t_env **envp, char *key)
{
	t_env	*current;
	t_env	*prev;
	t_env	*to_free;

	current = *envp;
	prev = NULL;
	while (current)
	{
		if (!ft_strcmp(current->key, key))
		{
			if (prev)
				prev->next = current->next;
			else
				*envp = current->next;
			to_free = current;
			current = current->next;
			free(to_free->key);
			free(to_free->value);
			free(to_free->full_str);
			free(to_free);
			continue ;
		}
		prev = current;
		current = current->next;
	}
}

void	exec_unset(t_all *all, t_tree *tree, t_env **envp)
{
	t_token		*t_current;

	t_current = tree->token->next;
	while (t_current)
	{
		unset_env_variable(envp, t_current->str);
		t_current = t_current->next;
	}
	all->exit_status = 0;
}
