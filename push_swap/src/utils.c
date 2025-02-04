/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:38:55 by artperez          #+#    #+#             */
/*   Updated: 2025/02/04 11:40:42 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list_a	*ft_lstnew(int content)
{
	t_list_a	*list;

	list = malloc(sizeof(t_list_a));
	if (list == NULL)
		return (NULL);
	list->a = content;
	list->next = NULL;
	return (list);
}