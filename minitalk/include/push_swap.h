/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:14 by artperez          #+#    #+#             */
/*   Updated: 2025/03/06 13:12:52 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_list
{
	int				nb;
	int				size_a;
	int				size_b;
	struct s_list	*next;
	struct s_list	*target;
	int				push_cost;
}			t_list;

void	ft_taking_list_split(char **argv, t_list **list_a);
void	ft_taking_list(char **argv, t_list **list_a);
t_list	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_list **lst, t_list *new);
void	check_list(t_list **list_a, char *str, char **tab);
void	free_all(t_list **list_a, char **tab);
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
bool	sort_good(t_list **list_a);
void	sort_list_b(t_list **list);
void	sort_list_b(t_list **list);
void	target(t_list **list_a, t_list **list_b);
int		ft_lstsize_ps(t_list *lst);
int		check_min(int nb, t_list *list, t_list **add_target);
void	add_cheapest(t_list **list_a, t_list **list_b);
void	reverse_a(int pos_a, t_list **list_a);
void	reverse_b(int pos_b, t_list **list_b);
void	add_b(t_list *push_node, t_list **list_b, t_list **list_a);
int		pos_target(t_list *list, t_list *target);
int		pc(int pos, int size);
int		check_max(int nb, t_list *list, t_list **add_target);
void	get_pcost_back(t_list **list_a, t_list **list_b);
void	sort_a(t_list **list_a, t_list **list_b);
void	add_cheapest_back(t_list **list_a, t_list **list_b);
void	target_back(t_list **list_a, t_list **list_b);
void	sort_3(t_list **list_a, t_list *current);
void	add_a(t_list *push_node, t_list **list_b, t_list **list_a);
void	min_ontop(t_list **list);
int		ft_strlen_int(int nbr);
char	*ft_itoa(int nbr);
bool	ft_same(char *str1, char *str2);
char	**set_up_split(char **tab, t_list **list, char *str, char **argv);
void	set_up_taking(t_list **list, char **argv, char *str);
void	exit_error(t_list **list, char **tab, char *str);
int		check_both(int push_cost, t_list **list_b, t_list **list_a,
			t_list *current_a);
void	reverse_bot(int pos_a, int pos_b, t_list **list_a, t_list **list_b);
void	reverse_top(int pos_a, int pos_b, t_list **list_a, t_list **list_b);
int		check_both_back(int push_cost, t_list **list_b,
			t_list **list_a, t_list *current_b);

#endif