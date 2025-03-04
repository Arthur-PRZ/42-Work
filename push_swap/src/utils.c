/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:38:55 by artperez          #+#    #+#             */
/*   Updated: 2025/03/03 14:45:14 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew_ps(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->nb = content;
	list->next = NULL;
	list->target = NULL;
	list->push_cost = 0;
	return (list);
}

void	ft_lstadd_back_ps(t_list **lst, t_list *new)
{
	t_list	*temp;

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

void	ft_lstadd_front_ps(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize_ps(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	check_list(t_list **list_a, char *str, char **tab)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			free_all(list_a, tab);
		}
		i++;
	}
}