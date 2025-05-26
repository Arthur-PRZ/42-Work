/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:56:20 by ctravers42        #+#    #+#             */
/*   Updated: 2025/04/23 10:17:07 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_size_quotes(char *str, int *i, int *j)
{
	(*i)++;
	while (str[*i] && str[(*i)++] != '\'')
		(*j)++;
	return (0);
}

int	get_size_dquotes_env(char *str, int *i, int *j)
{
	char	*env;
	char	*temp;

	temp = strndup_ms(str + *i + 1, get_env_size(str + *i));
	env = getenv(temp);
	free(temp);
	if (env != NULL)
		*j += ft_strlen(env);
	*i += get_env_size(str + *i) + 1;
	return (0);
}

int	get_size_dquotes_process(char *str, int *i, int *j)
{
	while (str[*i] && str[*i] != '\"' && str[*i] != '$')
	{
		(*j)++;
		(*i)++;
	}
	return (0);
}

int	get_size_dquotes(char *str, int *i, int *j, int *exit_status)
{
	(*i)++;
	while (str[*i] != '\"')
	{
		*j += skip_simples_quotes(str + *i);
		*i += skip_simples_quotes(str + *i);
		if (str[*i] == '$' && str[*i + 1] == '?')
		{
			*j += ft_int_strlen(*exit_status);
			*i += 2;
		}
		else if (str[*i] == '$')
			get_size_dquotes_env(str, i, j);
		else
			get_size_dquotes_process(str, i, j);
	}
	(*i)++;
	return (0);
}
