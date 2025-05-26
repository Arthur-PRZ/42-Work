/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:48:06 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/06 11:29:07 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_too_many_args(t_all *all, int *exit_status)
{
	if (all->tree->token->next && all->tree->token->next->next)
	{
		printf("Error: Too many args\n");
		*exit_status = 1;
		return (1);
	}
	return (0);
}

static int	check_numeric_arg(t_all *all)
{
	int	i;

	i = 0;
	if (all->tree->token->next && all->tree->token->next->str[0] == '-')
		i++;
	while (all->tree->token->next && all->tree->token->next->str[i])
	{
		if (!ft_isdigit(all->tree->token->next->str[i]))
		{
			printf("Error: Numeric arg required :%s \n",
				all->tree->token->next->str);
			free_all(all);
			exit(2);
		}
		i++;
	}
	return (0);
}

void	exec_exit(int *exit_status, t_all *all)
{
	int		exit_nbr;

	exit_nbr = 0;
	printf("exit\n");
	if (check_numeric_arg(all))
		return ;
	if (check_too_many_args(all, exit_status))
		return ;
	if (all->tree->token->next && all->tree->token->next->str)
	{
		exit_nbr = ft_atoi(all->tree->token->next->str);
		exit_nbr = exit_nbr % 256;
	}
	free_all(all);
	exit(exit_nbr);
}
