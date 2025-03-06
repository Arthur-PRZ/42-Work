/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:23:00 by artperez          #+#    #+#             */
/*   Updated: 2025/03/06 13:09:06 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(t_list **list, char **tab, char *str)
{
	write(2, "Error\n", 6);
	if (str != NULL)
		free(str);
	free_all(list, tab);
}

void	free_all(t_list **list, char **tab)
{
	int		a;
	t_list	*temp;
	t_list	*next;

	a = 0;
	if (tab != NULL)
	{
		while (tab[a])
		{
			free(tab[a]);
			a++;
		}
		free(tab);
	}
	if (list != NULL)
	{
		temp = *list;
		while (temp != NULL)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		exit (1);
	}
}
