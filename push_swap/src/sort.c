/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:00:32 by artperez          #+#    #+#             */
/*   Updated: 2025/02/17 12:53:01 by artperez         ###   ########.fr       */
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

void	sort_list_a(t_list **list)
{
	while (sort_good == 1)
	{
		
	}	
}

void	check_list(t_list **list_a, t_list **list_b)
{
	t_list *temp;
	
	temp = *list_b;
	if (temp->nb > (*list_a)->nb)
	{
		temp = (*list_b)->next;
		pb(list_b, list_a);
	}
}

void	sort_list_b(t_list **list)
{
	while (sort_good_decreasing == 1)
	{
		
	}	
}

add_b
{ 
	2 dans b
	while(ft_lstsize(list_a) > 3)
		target();
		add_cheapest();
	sort_a();
	while(ft_lstsize(list_a) < size)
		target_back();
		add_cheapest_back();
}
void	sort(t_list **list_a)
{
	int	size;
	
	size = ft_lstsize(*list_a);
	while(sort_good(list_a) == 1 && ft_lstsize(*list_a) == size)
	{
		add_b()
		

		sort_list(list_a);
		sort_list(list_b);
		check_list(list_a, list_b);
	}
}