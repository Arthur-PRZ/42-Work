/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:39:58 by artperez          #+#    #+#             */
/*   Updated: 2025/02/25 11:11:06 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_max(int nb, t_list *list, t_list **add_target)
{
	t_list	*bigger_value;
	int		smaller_b;
	
	smaller_b = list->nb;
	bigger_value = list;
	while(list != NULL) 
	{
		if (list->nb > nb && smaller_b > list->nb)
		{
			smaller_b = list->nb;
			bigger_value = list;
		}
		list = list->next;
		if(list == NULL)
		{
			*add_target = bigger_value;
			return (1);
		}
	}
	return (0);
}
