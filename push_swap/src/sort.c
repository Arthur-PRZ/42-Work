/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:00:32 by artperez          #+#    #+#             */
/*   Updated: 2025/02/25 11:06:41 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_good(t_list **list_a)
{
	t_list	*temp;
	int		value;

	temp = *list_a;
	while(temp->next != NULL)
	{
		value = temp->nb;
		temp = temp->next;
		if (value > temp->nb)
			return (1);
	}
	return (0);
}

int	sort_good_decreasing(t_list **list_a)
{
	t_list	*temp;
	int		value;

	temp = *list_a;
	while(temp->next != NULL)
	{
		value = temp->nb;
		temp = temp->next;
		if (value < temp->nb)
			return (1);
	}
	return (0);
}

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

int		check_min(int nb, t_list *list, t_list **add_target)
{
	t_list	*bigger_value;
	int		bigger_b;
	
	bigger_b = list->nb;
	bigger_value = list;
	while(list != NULL) 
	{
		if (list->nb < nb && bigger_b < list->nb)
		{
			bigger_b = list->nb;
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
		while (temp_a != NULL && check_min(temp_a->nb, temp_b, &(temp_a->target)) == 1 && temp_a != NULL)
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

void	reverse_a(int pos_a, t_list **list_a)
{
	int	size;
	
	size = ft_lstsize_ps(*list_a);
	if (pos_a < size / 2 || pos_a == size / 2)
	{
		while (pos_a != 0)
		{
			ra(list_a);
			pos_a--;
		}
	}
	else if (pos_a > size / 2)
	{
		while (pos_a != size - 1)
		{
			pos_a++;
		}
		rra(list_a);
	}
}

void	reverse_b(int pos_b, t_list **list_b)
{
	int	size;
	
	size = ft_lstsize_ps(*list_b);
	if (pos_b < size / 2 || pos_b == size / 2)
	{
		while (pos_b != 0)
		{
			rb(list_b);
			pos_b--;
		}
	}
	else if (pos_b > size / 2)
	{
		while (pos_b != size - 1)
		{
			rrb(list_b);
			pos_b++;
		}
		rrb(list_b);
	}
}
void	add_b(t_list *push_node, t_list **list_b, t_list **list_a)
{
	int	pos_a;
	int	pos_b;
	
	pos_a = pos_target(push_node, *list_a);
	pos_b = pos_target(push_node->target, *list_b);
	reverse_a(pos_a, list_a);
	reverse_b(pos_b, list_b);
	pb(list_a, list_b);
}

int	pos_target(t_list *list, t_list *target)
{
	int	pos;
	
	pos = 0;
	while(list != target && list != NULL)
	{
		pos++;
		list = list->next;
	}
	return (pos);
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

int	pc(int pos, int size)
{
	int	push_cost;
	int	mid_size;

	mid_size = size / 2;
	push_cost = 0;
	if (pos <  mid_size || pos == mid_size)
		push_cost = pos;
	else if (pos > mid_size)
		push_cost = pos - mid_size;
	return (push_cost);
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

void	sort_3(t_list **list_a)
{
	t_list *current;
	t_list *last_node;
	int		bigger_value;
	
	if (sort_good(list_a))
		return;
	current = *list_a;
	if (current->nb > current->next->nb && current->nb > current->next->next->nb)
		sa(list_a);
	current = *list_a;
	if (current->next->nb > current->next->next->nb)
		ra(list_a);
	current = *list_a;
	if (current->nb > current->next->nb)
		sa(list_a);
}

void	sort(t_list **list_a, t_list **list_b)
{
	int		size;
	
	size = ft_lstsize_ps(*list_a);
	if (size > 4)
	{
		pb(list_a, list_b);
		pb(list_a, list_b);
	}
	sort_b(list_a, list_b);
	sort_3(list_a)
	sort_a(list_a, list_b);
}

