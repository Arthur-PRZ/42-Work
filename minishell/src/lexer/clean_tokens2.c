/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tokens2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:04:41 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/02 10:47:37 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	pipe_rdr_repeat(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\'' || str[0] == '\"')
		return (true);
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
			return (false);
		if (str[i] == '|' && str[i + 1] == '<')
			return (false);
		if (str[i] == '|' && str[i + 1] == '>')
			return (false);
		if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
			return (false);
		if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
			return (false);
		if (str[i] == '>' && str[i + 1] == '<')
			return (false);
		if (str[i] == '<' && str[i + 1] == '>')
			return (false);
		i++;
	}
	return (true);
}

t_all	*clean_tokens_process(t_all	*all, char *res, int i, int j)
{
	while (all->token->str[i])
	{
		if (all->token->str[i] == '\'')
			all->token = clean_tokens_single_quote(all->token, &i, &j, res);
		else if (all->token->str[i] == '\"')
			all = clean_tokens_double_quote(all, &i, &j, res);
		else if (all->token->str[i] == '$')
		{
			if (all->token->str[i + 1] == '?')
			{
				all->token = clean_qm(all, &j, res);
				i += 2;
			}
			else
				all->token = clean_tokens_dollar(all, &i, &j, res);
		}
		else
			res[j++] = all->token->str[i++];
		if (!all->token)
			return (NULL);
		if (all->token->str == NULL)
			return (all);
	}
	res[j] = '\0';
	return (all);
}

t_all	*clean_tokens(t_all *all, int *exit_status)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (pipe_rdr_repeat(all->token->str) == false)
		return (ft_putstr_fd("Syntax error : unexpected token\n", 2),
			*exit_status = 2, NULL);
	if (quotes_check(all->token->str))
		return (ft_putstr_fd("Syntax error : quote missing\n", 2),
			*exit_status = 129, NULL);
	res = malloc(sizeof(char) * (get_size(all->token->str, all, i, j)
				+ 1));
	all = clean_tokens_process(all, res, i, j);
	if (!all->token)
		return (free(res), NULL);
	if (all->token->str == NULL)
		return (all);
	free(all->token->str);
	all->token->str = NULL;
	all->token->str = res;
	return (all);
}

t_token	*process_clean_token(t_token *token)
{
	if (token->is_env == false && is_valid_cmd(token->str)
		&& token->str[0] != '\0')
		token->arg_type = CMD;
	else if (token->arg_type == TYPE_UNKNOW)
		token->arg_type = ARGS;
	return (token);
}

t_token	*clean_qm(t_all *all, int *j, char *res)
{
	char	*temp;
	int		k;

	temp = ft_itoa(all->exit_status);
	k = 0;
	while (temp[k])
		res[(*j)++] = temp[k++];
	(free(temp), temp = NULL);
	return (all->token);
}
