/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:10:50 by artperez          #+#    #+#             */
/*   Updated: 2025/02/11 11:30:07 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void check_duplicate(t_list **list_a, char **tab)
{
	int		number;
	t_list *temp;
	t_list *i;
	
	temp = *list_a;
	while (temp != NULL)
	{
		number = temp->nb;
		i = temp->next;
		while (i != NULL)
		{
			if (number == i->nb)
				error_argument(list_a, tab);
			i = i->next;
		}
		temp = temp->next;
	}
}