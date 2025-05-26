/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_managements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:58:04 by artperez          #+#    #+#             */
/*   Updated: 2025/05/06 10:43:40 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_invalid_pipe(t_token *current, int *exit_status)
{
	if (current->next && current->arg_type == PIPE
		&& current->next->arg_type != CMD)
	{
		*exit_status = 127;
		ft_putstr_fd("Syntax error : CMD not found\n", 2);
		return (false);
	}
	return (true);
}

static bool	is_invalid_redir(t_token *current, int *exit_status)
{
	if (current->next && is_rdr(current->str)
		&& current->next->arg_type != ARGS)
	{
		*exit_status = 127;
		ft_putstr_fd("Syntax error : Unexpected token\n", 2);
		return (false);
	}
	return (true);
}

bool	is_cmd_first(int *exit_status, t_token *tokens)
{
	t_token	*current;

	current = tokens;
	if (is_rdr(tokens->str))
	{
		*exit_status = 0;
		return (true);
	}
	if (current->arg_type != CMD || dot_or_slash(current->str))
	{
		if (is_rdr(tokens->str) || current->arg_type == PIPE)
			*exit_status = 2;
		else
			*exit_status = 127;
		return (ft_putstr_fd("Syntax error : CMD not found\n", 2), false);
	}
	current = current->next;
	while (current)
	{
		if (!is_invalid_pipe(current, exit_status)
			|| !is_invalid_redir(current, exit_status))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	check_last_token(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (!current->next && (current->arg_type == PIPE
				|| is_rdr(current->str)) && current->arg_type != ARGS)
			return (ft_putstr_fd("Syntax error : Unexpected token\n", 2),
				false);
		current = current->next;
	}
	return (true);
}

bool	errors_managements(t_token *tokens, int *exit_status)
{
	if (tokens->str[0] == '\0')
	{
		ft_putstr_fd("Syntax error : CMD not found\n", 2);
	}
	if (!pipe_rdr_follow(tokens))
	{
		*exit_status = 2;
		return (true);
	}
	if (!is_cmd_first(exit_status, tokens))
		return (true);
	if (!check_last_token(tokens))
	{
		*exit_status = 2;
		return (true);
	}
	return (false);
}
