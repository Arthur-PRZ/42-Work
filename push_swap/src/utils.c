/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:38:55 by artperez          #+#    #+#             */
/*   Updated: 2025/02/10 10:37:22 by artperez         ###   ########.fr       */
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

void error_argument(t_list_a **list_a, char **tab)
{
	int	a;
	t_list_a	*temp;
	t_list_a	*next;
	
	temp = *list_a;
	a = 0;
	if (tab != NULL)
	{
		while(tab[a])
		{
			free(tab[a]);
			a++;
		}
		free(tab);
	}
	while(temp->next != NULL)
	{
		*next = list_a->next;
		free(temp);
		temp = next;
	}
	write(1, "Error\nArguments invalid.\n", 27);
}

void	check_list(t_list_a **list_a, char *str, char **tab)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_argument(list_a, tab);
		i++;
	}
}