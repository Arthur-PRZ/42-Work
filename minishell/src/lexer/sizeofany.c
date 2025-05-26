/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeofany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:00:47 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/02 10:30:23 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_size_env(char *str, int *i, int *j, t_all *all)
{
	char	*env;
	char	*temp;

	temp = strndup_ms(str + *i + 1, get_env_size(str + *i));
	env = get_env_value(all->env, temp);
	free(temp);
	if (env != NULL)
		*j += ft_strlen(env);
	*i += get_env_size(str + *i) + 1;
	return (0);
}

int	get_size(char *str, t_all *all, int i, int j)
{
	while (str[i])
	{
		if (str[i] && str[i] == '\'')
			get_size_quotes(str, &i, &j);
		else if (str[i] == '\"' && str[i])
			get_size_dquotes(str, &i, &j, &all->exit_status);
		else if (str[i])
		{
			if (str[i] == '$' && str[i + 1] == '?')
			{
				j = j + ft_int_strlen(all->exit_status);
				i += 2;
			}
			else if (str[i] == '$')
				get_size_env(str, &i, &j, all);
			else
			{
				j++;
				i++;
			}
		}
	}
	return (j);
}

int	get_env_size(char *str)
{
	int	i;

	i = 1;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\"' && str[i] != '\'' && str[i] != '$'
		&& str[i] != '=' && str[i] != '\n' && str[i] != '\t' && str[i] != ' '
		&& str[i] != '?')
		i++;
	return (i - 1);
}

bool	is_first_cmd(t_token *head, t_token *token)
{
	t_token	*current;
	t_token	*prev;

	current = head;
	prev = NULL;
	while (current && current != token)
	{
		prev = current;
		current = current->next;
	}
	if (prev == NULL || prev->str[0] == '|')
		return (true);
	return (false);
}
