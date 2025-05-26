/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:57:46 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 10:59:29 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_env_to_end(t_env *env, t_env *new)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	add_new_env_variable(t_env **env, char *key, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->full_str = get_full_str(new->key, new->value);
	new->next = NULL;
	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	add_env_to_end(*env, new);
}

void	update_existing_env_value(t_env *env, char *value)
{
	free(env->value);
	free(env->full_str);
	env->value = ft_strdup(value);
	env->full_str = get_full_str(env->key, env->value);
}

int	is_matching_key(char *env_key, char *key)
{
	return (ft_strlen(env_key) == ft_strlen(key)
		&& ft_strncmp(env_key, key, ft_strlen(key)) == 0);
}

void	set_env_value(t_env **env, char *key, char *value)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (is_matching_key(tmp->key, key))
		{
			update_existing_env_value(tmp, value);
			return ;
		}
		tmp = tmp->next;
	}
	add_new_env_variable(env, key, value);
}
