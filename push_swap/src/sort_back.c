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

#include "../include/push_swap.h"

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
	
	pos_a = pos_target(push_node->target, *list_a);
	pos_b = pos_target(push_node, *list_b);
	reverse_a(pos_a, list_a);
	reverse_b(pos_b, list_b);
	pa(list_a, list_b);
}

void	get_pcost_back(t_list **list_a, t_list **list_b)
{
	int		push_cost;
	int		size_a;
	int		size_b;
	t_list *current_a;

	size_a = ft_lstsize_ps(*list_a);
	size_b = ft_lstsize_ps(*list_b);
	current_b = *list_b;
	while (current_b != NULL)
	{
		push_cost = 0;
		push_cost = pc(pos_target(*list_a, current_b->target), size_a)
		 	+ pc(pos_target(*list_b, current_b), size_b);
		push_cost++;
		current_b->push_cost = push_cost;
		if (push_cost == 1)
			return ;
		current_b = current_b->next;
	}
}

void	add_cheapest_back(t_list **list_a, t_list **list_b)
{
	t_list	*current_a;
	t_list	*push_node;
	int		smaller_pc;

	current_b = *list_b;
	push_node = *list_b;
	while (current_b != NULL)
	{
		smaller_pc = current_b->push_cost;
		if (smaller_pc == 1)
		{
			add_a(push_node, list_b, list_a);
			return ;
		}
		if (smaller_pc > current_b->push_cost)
		{
			smaller_pc = current_b->push_cost;
			push_node = current_b;
		}
		current_b = current_b->next;
	}
	add_a(push_node, list_b, list_a);
}

void	target_back(t_list **list_a, t_list **list_b)
{
	t_list *temp_a;
	t_list *temp_b;
	int		closest_bigger;
	
	temp_b = *list_b;
	while (temp_b != NULL)
	{
		temp_a = *list_a;
		closest_bigger = __INT_MAX__;
		while (check_max(temp_b->nb, temp_a, &(temp_b->target)) == 1 && temp_b != NULL)
		 	temp_b = temp_b->next;
		while (temp_a != NULL && temp_b != NULL)
		{
			if (temp_a->nb > temp_b->nb 
				&& closest_bigger > temp_a->nb - temp_b->nb)
			{
				closest_bigger = temp_a->nb - temp_b->nb;
				temp_b->target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (temp_b != NULL)
			temp_b = temp_b->next;
	}
}
