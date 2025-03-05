/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:00:32 by artperez          #+#    #+#             */
/*   Updated: 2025/03/05 10:49:53 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


// void	check_list(t_list **list_a, t_list **list_b)
// {
// 	t_list *temp;
	
// 	temp = *list_b;
// 	if (temp->nb > (*list_a)->nb)
// 	{
// 		temp = (*list_b)->next;
// 		pb(list_b, list_a);
// 	}
// }

// void	sort_a(t_list **list)
// {
// 	// while (sort_good_decreasing == 1)
// 	// {
		
// 	// }	
// }

void	add_b(t_list *push_node, t_list **list_b, t_list **list_a)
{
	int	pos_a;
	int	pos_b;
	int		size_b;

	pos_a = pos_target(*list_a, push_node);
	pos_b = pos_target(*list_b, push_node->target);
	size_b = ft_lstsize_ps(*list_b);
	reverse_top(pos_a, pos_b, list_a, list_b);
	reverse_bot(pos_a, pos_b, list_a, list_b);
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
		push_cost = check_both(push_cost, list_b, list_a, current_a);
		push_cost++;
		current_a->push_cost = push_cost;
		if (push_cost == 1)
			return ;
		current_a = current_a->next;
	}
}

void	sort_b(t_list **list_a, t_list **list_b)
{
	while (ft_lstsize_ps(*list_a) > 3)
	{
		target(list_a, list_b);
		get_pcost(list_a, list_b);
		add_cheapest(list_a, list_b);
	}
}

void	min_ontop(t_list **list)
{
	t_list	*current_a;
	t_list	*smaller_node;
	int		smaller_value;

	current_a = *list;
	smaller_value = current_a->nb;
	smaller_node = current_a;
	while (current_a != NULL)
	{
		if (smaller_value > current_a->nb)
		{
			smaller_value = current_a->nb;
			smaller_node = current_a;
		}
		current_a = current_a->next;
	}
	reverse_a(pos_target(*list, smaller_node), list);
}

void	sort(t_list **list_a, t_list **list_b)
{
	int		size;
	t_list	*current;

	size = ft_lstsize_ps(*list_a);
	current = *list_a;
	if (size > 4)
	{
		pb(list_a, list_b);
		pb(list_a, list_b);
	}
	else if(size == 4)
		pb(list_a, list_b);
	else if(size == 3)
	{
		sort_3(list_a, current);
		return ;
	}
	sort_b(list_a, list_b);
	current = *list_a;
	if (sort_good(list_a) == false)
		sort_3(list_a, current);
	sort_a(list_a, list_b);
	min_ontop(list_a);
}
