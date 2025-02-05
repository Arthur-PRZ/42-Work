/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:38:55 by artperez          #+#    #+#             */
/*   Updated: 2025/02/05 09:27:35 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list_a	*ft_lstnew_ps(int content)
{
	t_list_a	*list;

	list = malloc(sizeof(t_list_a));
	if (list == NULL)
		return (NULL);
	list->a = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back_ps(t_list_a **lst, t_list_a *new)
{
	t_list_a	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp != NULL && temp->next != NULL )
		temp = temp->next;
	temp->next = new;
}