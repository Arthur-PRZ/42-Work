/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:59:18 by artperez          #+#    #+#             */
/*   Updated: 2025/03/05 10:37:49 by artperez         ###   ########.fr       */
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

void	reverse_top(int pos_a, int pos_b, t_list **list_a, t_list **list_b)
{
	int	size_a;
	int	size_b;
	
	size_a = ft_lstsize_ps(*list_a);
	size_b = ft_lstsize_ps(*list_b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(list_a, list_b);
			pos_a--;
			pos_b--;
		}
	}
	while (pos_a > 0 && pos_a <= size_a / 2)
	{
		ra(list_a);
		pos_a--;
	}
	while (pos_b > 0 && pos_b <= size_b / 2)
	{
		rb(list_b);
		pos_b--;
	}
}

void	reverse_bot(int pos_a, int pos_b, t_list **list_a, t_list **list_b)
{
	int	size_a;
	int	size_b;
	
	size_a = ft_lstsize_ps(*list_a);
	size_b = ft_lstsize_ps(*list_b);
	if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		while (pos_a < size_a && pos_b < size_b)
		{
			rrr(list_a, list_b);
			pos_a++;
			pos_b++;
		}
	}
	while (pos_a != size_a && pos_a > size_a / 2)
	{
		rra(list_a);
		pos_a++;
	}
	while (pos_b < size_b && pos_b > size_b / 2)
	{
		rrb(list_b);
		pos_b++;
	}
}

void	reverse(int pos_a, int pos_b, t_list **list_a, t_list **list_b)
{
	int	size_a;
	int	size_b;
	
	size_a = ft_lstsize_ps(*list_a);
	size_b = ft_lstsize_ps(*list_b);
	if (pos_a <= size_a / 2 || pos_b <= size_b / 2)
		reverse_top(pos_a, pos_b, list_a, list_b);
	else if (pos_a > size_a / 2 || pos_b > size_b / 2)
		reverse_bot(pos_a, pos_b, list_a, list_b);
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

// void	reverse_b(int pos_b, t_list **list_b)
// {
// 	int	size;
	
// 	size = ft_lstsize_ps(*list_b);
// 	if (pos_b < size / 2 || pos_b == size / 2)
// 	{
// 		while (pos_b != 0)
// 		{
// 			rb(list_b);
// 			pos_b--;
// 		}
// 	}
// 	else if (pos_b > size / 2)
// 	{
// 		while (pos_b < size - 1)
// 		{
// 			rrb(list_b);
// 			pos_b++;
// 		}
// 		rrb(list_b);
// 	}
// }