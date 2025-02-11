/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:23:00 by artperez          #+#    #+#             */
/*   Updated: 2025/02/11 11:30:13 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void error_argument(t_list **list_a, char **tab)
{
	int	a;
	t_list	*temp;
	t_list	*next;
	
	temp = *list_a;
	a = 0;
	if (tab != NULL)
	{
		while(tab[a])
		{
			free(tab[a]);
			a++;
		}
		free(tab);
	}
	while(temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	write(1, "Error\nArguments invalid.\n", 27);
	exit (1);
}