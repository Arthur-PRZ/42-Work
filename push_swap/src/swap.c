/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:18 by artperez          #+#    #+#             */
/*   Updated: 2025/02/12 10:35:18 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list **list)
{
	ft_printf("sa\n");
	swap(list);
}

void	sb(t_list **list)
{
	ft_printf("sb\n");
	swap(list);
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}

void	swap(t_list **list)
{
	t_list	*temp;
	t_list	*after;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp = *list;
	*list = (*list)->next;
	after = (*list)->next;
	(*list)->next = temp;
	temp->next = after;
}