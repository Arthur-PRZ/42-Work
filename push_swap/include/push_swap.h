/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:14 by artperez          #+#    #+#             */
/*   Updated: 2025/02/11 11:29:22 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list
{
	int	a;
	struct s_list *next;
} t_list;

void	ft_taking_list(char **argv, t_list **
list_a, int argc);
t_list	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_list **lst, t_list *new);
void	check_list(t_list **list_a, char *str, char **tab);
void	error_argument(t_list **list_a, char **tab);
void	check_duplicate(t_list **list_a, char **tab);

#include "../libft/libft.h"


#endif