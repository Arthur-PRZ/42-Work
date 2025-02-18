/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:14 by artperez          #+#    #+#             */
/*   Updated: 2025/02/18 11:39:41 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_list
{
	int	nb;
	struct s_list *next;
	struct s_list *target;
} t_list;

void	ft_taking_list(char **argv, t_list **
list_a, int argc);
t_list	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_list **lst, t_list *new);
void	check_list(t_list **list_a, char *str, char **tab);
void	error_argument(t_list **list_a, char **tab);
void	check_duplicate(t_list **list_a, char **tab);
void	sa(t_list **list);
void	sb(t_list **list);
void	swap(t_list **list);
void	ss(t_list **list_a, t_list **list_b);
void	pa(t_list **list_taking, t_list **list_giving);
void	push(t_list **list_taking, t_list **list_giving);
void	pb(t_list **list_a, t_list **list_b);
void	rotate(t_list **list);
void	ra(t_list **list_a);
void	rb(t_list **list_b);
void	rr(t_list **list_a, t_list **list_b);
void	reverse_rotate(t_list **list);
void	rrb(t_list **list_b);
void	rra(t_list **list_a);
void	rrr(t_list **list_a, t_list **list_b);
void	ft_lstadd_front_ps(t_list **lst, t_list *new);
void	sort(t_list **list_a, t_list **list_b);
int		sort_good(t_list **list_a);
void	sort_list_b(t_list **list);
void	sort_list_b(t_list **list);
int		sort_good_decreasing(t_list **list_a);
void	target(t_list **list_a, t_list **list_b);
int		ft_lstsize_ps(t_list *lst);






#endif