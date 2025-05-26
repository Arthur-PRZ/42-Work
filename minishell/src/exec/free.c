/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:01:18 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 11:05:27 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env(t_env **tokens)
{
	t_env	*current;
	t_env	*next;

	current = *tokens;
	while (current)
	{
		next = current->next;
		free(current->full_str);
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	*tokens = NULL;
}

void	free_tab(char **envc)
{
	int	i;

	i = 0;
	while (envc[i])
	{
		free(envc[i]);
		envc[i] = NULL;
		i++;
	}
	free(envc);
	envc = NULL;
}
