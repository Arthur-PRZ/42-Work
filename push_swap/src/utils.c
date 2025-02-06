/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:38:55 by artperez          #+#    #+#             */
/*   Updated: 2025/02/06 10:51:51 by artperez         ###   ########.fr       */
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

void	check_list(t_list_a **list_a, char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_argument(list_a, str);
		i++;
	}
	list_a = NULL;
}