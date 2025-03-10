/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:39:03 by artperez          #+#    #+#             */
/*   Updated: 2025/03/06 11:16:28 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_list **sender, t_list **receiver)
{
	t_list	*temp;

	if (!*sender)
		return ;
	temp = *sender;
	*sender = (*sender)->next;
	if (!*receiver)
	{
		*receiver = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *receiver;
		*receiver = temp;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}
