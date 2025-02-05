/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:14 by artperez          #+#    #+#             */
/*   Updated: 2025/02/05 13:22:59 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list_a
{
	int	a;
	struct s_list_a *next;
} t_list_a;

void	ft_taking_list(char **argv, t_list_a **
list_a, int argc);
t_list_a	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_list_a **lst, t_list_a *new);

#include "../libft/libft.h"


#endif