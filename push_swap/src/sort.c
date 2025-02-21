/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:00:32 by artperez          #+#    #+#             */
/*   Updated: 2025/02/21 15:36:17 by artperez         ###   ########.fr       */
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
	while(nb < list->nb)
	{
		if (bigger_b < list->nb)
			bigger_value = list;
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

// void	add_cheapest(t_list **list_a, t_list **list_b)
// {
// 	push_cost();
	
// }

int	pos_target(t_list *list, t_list *target)
{
	int	pos;
	
	pos = 0;
	while(list != target)
	{
		pos++;
		list = list->next;
	}
	return (pos);
	
}	

void	get_pcost(t_list **list_a, t_list **list_b)
{
	int		push_cost;
	t_list *current_a;

	current_a = *list_a;
	while (current_a != NULL)
	{
		push_cost = 0;
		push_cost = pc(pos_target(*list_b, (*list_a)->target),ft_lstsize_ps(*list_b))
			+ pc(*list_a, ft_lstsize_ps(*list_a));
		current_a->push_cost = push_cost;
		current_a = current_a->next;
	}
}

int	pc(int pos, int size)
{
	int i;
	int	push_cost;

	i = 0;
	push_cost = 0;
	if (pos < size / 2)
	{
		while (pos != 0)
		{
			i--;
			push_cost++;
		}	
	}
	else if (pos > size / 2)
	{
		while (pos != size)
		{
			i++;
			push_cost++;
		}
		push_cost++;
	}
	return (push_cost);
}

void	sort_b(t_list **list_a, t_list **list_b)
{
	// while (ft_lstsize_ps(*list_a) > 3)
	{
		target(list_a, list_b);
		get_pcost(list_a, list_b);
		// add_cheapest(list_a, list_b);
	}
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
	// while(ft_lstsize(list_a) > 3)
	// {
	// 	target(list_a, list_b);
	// 	add_cheapest();
	// }
	// sort_a();
	// while(ft_lstsize(list_a) < size)
	// {
	// 	target_back();
	// 	add_cheapest_back();
	// }
}

