/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:42 by artperez          #+#    #+#             */
/*   Updated: 2025/02/27 10:04:07 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (*list == NULL || (*list)->next == NULL)
		return;
	last = *list;
	while (last->next != NULL)
		last = last->next;
	second_last = *list;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *list;
	*list = last;
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
