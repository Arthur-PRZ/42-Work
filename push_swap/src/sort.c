/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:00:32 by artperez          #+#    #+#             */
/*   Updated: 2025/02/19 13:32:12 by artperez         ###   ########.fr       */
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

int	closestzero_min(int	nb, int nb2)
{
	int	closestzero;

	while(temp != NULL)
	{
		if (nb > nb2)
			closestzero = nb - nb2;	
		temp = temp->next
	}
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
		while (temp_b != NULL)
		{
			if (closestzero_min(temp_a->nb, temp_b->nb) < smaller_value)
			{
				smaller_value = closestzero_min();
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
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
	target(list_a, list_b);
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
