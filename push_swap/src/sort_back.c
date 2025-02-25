/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:37:02 by artperez          #+#    #+#             */
/*   Updated: 2025/02/25 11:18:52 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_a(t_list **list_a, t_list **list_b)
{
	while (ft_lstsize_ps(*list_b) != NULL)
	{
		target_back(list_a, list_b);
		get_pcost_back(list_a, list_b);
		add_cheapest_back(list_a, list_b);
	}
}

void	add_a(t_list *push_node, t_list **list_b, t_list **list_a)
{
	int	pos_a;
	int	pos_b;
	
	pos_a = pos_target(push_node, *list_a);
	pos_b = pos_target(push_node->target, *list_b);
	reverse_a(pos_a, list_a);
	reverse_b(pos_b, list_b);
	pb(list_a, list_b);
}

void	get_pcost(t_list **list_a, t_list **list_b)
{
	int		push_cost;
	int		size_a;
	int		size_b;
	t_list *current_a;

	size_a = ft_lstsize_ps(*list_a);
	size_b = ft_lstsize_ps(*list_b);
	current_a = *list_a;
	while (current_a != NULL)
	{
		push_cost = 0;
		push_cost = pc(pos_target(*list_b, current_a->target), size_b)
		 	+ pc(pos_target(*list_a, current_a), size_a);
		push_cost++;
		current_a->push_cost = push_cost;
		if (push_cost == 1)
			return ;
		current_a = current_a->next;
	}
}

void	add_cheapest(t_list **list_a, t_list **list_b)
{
	t_list	*current_a;
	t_list	*push_node;
	int		smaller_pc;

	current_a = *list_a;
	push_node = *list_a;
	while (current_a != NULL)
	{
		smaller_pc = current_a->push_cost;
		if (smaller_pc == 1)
		{
			add_b(push_node, list_b, list_a);
			return ;
		}
		if (smaller_pc > current_a->push_cost)
		{
			smaller_pc = current_a->push_cost;
			push_node = current_a;
		}
		current_a = current_a->next;
	}
	add_b(push_node, list_b, list_a);
}

void	target(t_list **list_a, t_list **list_b)
{
	t_list *temp_a;
	t_list *temp_b;
	int		smaller_value;
	
	temp_a = *list_a;
	while (temp_a != NULL)
	{
		temp_b = *list_b;
		smaller_value = temp_b->nb;
		while (temp_a != NULL && check_max(temp_b->nb, temp_a, &(temp_b->target)) == 1 && temp_a != NULL)
		 	temp_a = temp_a->next;
		while (temp_a != NULL && temp_b != NULL)
		{
			if (temp_a->nb > temp_b->nb 
				&& smaller_value > temp_a->nb - temp_b->nb)
			{
				smaller_value = temp_a->nb - temp_b->nb;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (temp_a != NULL)
			temp_a = temp_a->next;
	}
}