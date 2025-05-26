/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:10:58 by artperez          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:28 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_resources(t_all *all)
{
	if (all && all->env)
		free_env(&all->env);
	if (all)
	{
		free(all);
		all = NULL;
	}
	rl_clear_history();
}

void	free_all(t_all *all)
{
	if (all && all->tree && all->tree->token)
		free_list(&all->tree->token);
	if (all && all->tree)
		free_tree(all->tree);
	else if (all->token)
		free_list(&all->token);
	if (all && all->env)
		free_env(&all->env);
	if (all)
		(free(all), all = NULL);
}
