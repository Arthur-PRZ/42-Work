/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:58:55 by ctravers42        #+#    #+#             */
/*   Updated: 2025/04/03 11:59:33 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quotes_check_single(char *str, int *i, int *q)
{
	(*q)++;
	(*i)++;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	if (str[*i] == '\'')
		(*q)++;
	return (0);
}

int	quotes_check_double(char *str, int *i, int *dq)
{
	(*dq)++;
	(*i)++;
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	if (str[*i] == '\"')
		(*dq)++;
	return (0);
}

int	quotes_check_helper(char *str, int *i, int *q, int *dq)
{
	if (str[*i] == '\'')
		quotes_check_single(str, i, q);
	if (str[*i] == '\"')
		quotes_check_double(str, i, dq);
	return (0);
}

int	quotes_check(char *str)
{
	int	q;
	int	dq;
	int	i;

	q = 0;
	dq = 0;
	i = 0;
	while (str[i])
	{
		quotes_check_helper(str, &i, &q, &dq);
		if (str[i])
			i++;
	}
	if (q % 2 == 0 && dq % 2 == 0)
		return (0);
	return (1);
}
