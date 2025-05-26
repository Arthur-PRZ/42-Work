/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tokens1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:03:48 by ctravers42        #+#    #+#             */
/*   Updated: 2025/04/23 12:24:09 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*clean_tokens_single_quote(t_token *tokens, int *i, int *j, char *res)
{
	(*i)++;
	while (tokens->str[*i] != '\'' && tokens->str[*i] != '\0')
	{
		res[*j] = tokens->str[*i];
		(*j)++;
		(*i)++;
	}
	tokens->is_clean = true;
	(*i)++;
	return (tokens);
}

t_all	*clean_tokens_env_process(t_all *all, int *i, int *j, char *res)
{
	int		a;
	char	*env_var;
	char	*temp;

	a = 0;
	if (all->token->str[*i] == '?')
	{
		clean_qm(all, j, res);
		return (all);
	}
	temp = strndup_ms(all->token->str + *i + 1,
			get_env_size(all->token->str + *i));
	env_var = get_env_value(all->env, temp);
	free(temp);
	temp = NULL;
	if (!env_var)
	{
		if (get_env_size(all->token->str) == (int)ft_strlen(all->token->str))
			(free(all->token->str), free(res), all->token->str = NULL);
		return (all);
	}
	while (env_var[a])
		res[(*j)++] = env_var[a++];
	return (all);
}

t_all	*clean_tokens_env(t_all *all, int *i, int *j, char *res)
{
	all = clean_tokens_env_process(all, i, j, res);
	if (!all->token)
		return (NULL);
	if (all->token->str != NULL)
		*i = *i + get_env_size(all->token->str + *i) + 1;
	all->token->is_env = true;
	return (all);
}

t_token	*clean_tokens_dollar(t_all *all, int *i, int *j, char *res)
{
	all = clean_tokens_env_process(all, i, j, res);
	if (!all->token)
		return (NULL);
	if (all->token->str != NULL)
	{
		*i = *i + get_env_size(all->token->str + *i) + 1;
		*i = *i + skip_quotes(all->token->str + *i);
	}
	all->token->is_env = true;
	return (all->token);
}

t_all	*clean_tokens_double_quote(t_all *all, int *i, int *j, char *res)
{
	(*i)++;
	while (all->token->str[*i] != '\"' && all->token->str[*i] != '\0')
	{
		if (all->token->str[*i] == '$' && all->token->str[*i + 1] == '?')
		{
			all->token = clean_qm(all, j, res);
			*i += 2;
		}
		else if (all->token->str[*i] == '$')
		{
			all = clean_tokens_env(all, i, j, res);
			if (!all->token)
				return (NULL);
		}
		else
			res[(*j)++] = all->token->str[(*i)++];
		all->token->is_clean = true;
	}
	if (all->token->str[*i] == '\"')
		(*i)++;
	return (all);
}
