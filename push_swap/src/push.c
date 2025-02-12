/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:39:03 by artperez          #+#    #+#             */
/*   Updated: 2025/02/12 11:29:29 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_list **list_taking, t_list **list_giving)
{
	t_list	*first;
	
	if (*list_giving == NULL)
        return;
	
	first = *list_giving;
	*list_giving = (*list_giving)->next;
	first->next = *list_taking;
	*list_taking = first;
}

void	pa(t_list **list_a, t_list **list_b)
{
	printf("pa\n");
	push(list_a, list_b);
}

void	pb(t_list **list_a, t_list **list_b)
{
	printf("pb\n");
	push(list_b, list_a);
}