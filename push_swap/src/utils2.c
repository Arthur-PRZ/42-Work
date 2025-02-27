/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:59:18 by artperez          #+#    #+#             */
/*   Updated: 2025/02/26 15:50:30 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

bool	sort_good(t_list **list_a)
{
	t_list	*temp;
	int		value;

	temp = *list_a;
	while(temp->next != NULL)
	{
		value = temp->nb;
		temp = temp->next;
		if (value > temp->nb)
			return (false);
	}
	return (true);
}

int		check_min(int nb, t_list *list, t_list **add_target)
{
	t_list	*bigger_value;
	t_list	*current;
	int		bigger_b;
	
	bigger_b = -1;
	bigger_value = NULL;
	current = list;
    while (current != NULL)
    {
        if (current->nb < nb)
            return 0;
        current = current->next;
    }
	while(list != NULL) 
	{
		if (list->nb > bigger_b && nb < list->nb)
		{
			bigger_b = list->nb;
			bigger_value = list;
		}
		list = list->next;
	}
    *add_target = bigger_value;
    return (1);
}

int	pc(int pos, int size)
{
	int	push_cost;
	int	mid_size;

	mid_size = size / 2;
	push_cost = 0;
	if (pos < mid_size || pos == mid_size)
		push_cost = pos;
	else if (pos > mid_size)
		push_cost = pos - mid_size;
	return (push_cost);
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
			rra(list_a);
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
		while (pos_b < size - 1)
		{
			rrb(list_b);
			pos_b++;
		}
		rrb(list_b);
	}
}