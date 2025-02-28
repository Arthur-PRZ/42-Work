/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:23:00 by artperez          #+#    #+#             */
/*   Updated: 2025/02/28 09:35:47 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void free_all(t_list **list, char **tab)
{
	int	a;
	t_list	*temp;
	t_list	*next;
	
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
	if (list != NULL && *list != NULL)
	{
		temp = *list;
		while(temp != NULL)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
	}
	exit (1);
}

