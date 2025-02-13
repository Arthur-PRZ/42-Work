/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:42 by artperez          #+#    #+#             */
/*   Updated: 2025/02/13 09:50:42 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*second;
	
	last = *list;
	second = (*list)->next;
	while (last->next != NULL)
		last = last->next;
	ft_lstadd_front_ps(list, last);
	last->next = NULL;
}

void	rra(t_list **list_a)
{
	ft_printf("rra\n");
	reverse_rotate(list_a);
}

void	rrb(t_list **list_b)
{
	ft_printf("rrb\n");
	reverse_rotate(list_b);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	ft_printf("rrr\n");
	reverse_rotate(list_a);
	reverse_rotate(list_b);
}