/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:12 by artperez          #+#    #+#             */
/*   Updated: 2025/03/06 11:17:35 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*old_first;

	old_first = *list;
	first = (*list)->next;
	ft_lstadd_back_ps(list, *list);
	*list = first;
	old_first->next = NULL;
}

void	ra(t_list **list_a)
{
	ft_printf("ra\n");
	rotate(list_a);
}

void	rb(t_list **list_b)
{
	ft_printf("rb\n");
	rotate(list_b);
}

void	rr(t_list **list_a, t_list **list_b)
{
	ft_printf("rr\n");
	rotate(list_a);
	rotate(list_b);
}
