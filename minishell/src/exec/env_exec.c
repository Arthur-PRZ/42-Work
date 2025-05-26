/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:29:19 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 11:45:16 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	extractval(char *entry, char **key, char **value, int *key_len)
{
	char	*equal_pos;

	equal_pos = ft_strchr(entry, '=');
	if (!equal_pos)
		return (0);
	*key_len = equal_pos - entry;
	*key = ft_substr(entry, 0, *key_len);
	*value = ft_strdup(equal_pos + 1);
	if (!(*key) || !(*value))
	{
		free(*key);
		free(*value);
		return (0);
	}
	return (1);
}

static t_env	*append_env(t_env *head, t_env **tail, char *key, char *value)
{
	t_env	*new_node;

	new_node = create_node_env(key, value);
	free(key);
	free(value);
	if (!head)
	{
		head = new_node;
		*tail = head;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = (*tail)->next;
	}
	return (head);
}

t_env	*create_env_array_ms(int i, int key_len, t_env *head, char **envp)
{
	t_env	*tail;
	char	*key;
	char	*value;

	tail = NULL;
	while (envp[i])
	{
		if (extractval(envp[i], &key, &value, &key_len))
			head = append_env(head, &tail, key, value);
		i++;
	}
	return (head);
}
