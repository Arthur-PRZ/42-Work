/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_managements2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:43:47 by artperez          #+#    #+#             */
/*   Updated: 2025/05/06 10:43:58 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	pipe_rdr_follow(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->next && current->arg_type == PIPE
			&& current->next->arg_type == PIPE)
			return (ft_putstr_fd("Syntax error : Unexpected token\n", 2),
				false);
		if (current->next && is_rdr(current->str)
			&& is_rdr(current->next->str))
			return (ft_putstr_fd("Syntax error : Unexpected token\n", 2),
				false);
		current = current->next;
	}
	return (true);
}

bool	dot_or_slash(char *str)
{
	int	i;

	i = 0;
	if (str && str[0] == '.' && (str[1] == '\0'
			|| (str[1] == '.' && str[2] == '\0')))
		return (true);
	while (str[i] == '.' || str[i] == '/')
		i++;
	if (str[i] == '\0' && i != 0)
		return (true);
	return (false);
}
