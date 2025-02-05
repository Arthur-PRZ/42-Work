/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:23:10 by artperez          #+#    #+#             */
/*   Updated: 2025/02/05 13:23:22 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_taking_list(char **argv, t_list_a **list_a, int argc)
{
	int	a;
	char	**tab;
	t_list_a	*new_node;
	
	a = 1;
	tab = ft_split(argv[1], ' ');
	if (tab == NULL)
		return ;
	while (argc == 2)
	{
		if (a == 0)
			*list_a = ft_lstnew_ps(ft_atoi(tab[0]));
		a++;
		if (tab[a] == NULL)
			break ;
		new_node = ft_lstnew_ps(ft_atoi(tab[a]));
		// free nl
		ft_lstadd_back_ps(list_a, new_node);
		list_a = &(*list_a)->next;
	}
	// while (argv[a])
	// {
	// 	if (a == 0)
	// 		ft_lstnew_ps(ft_atoi(argv[1]));
	// 	list_a->a = ft_atoi(argv[a]);
	// 	list_a = list_a->next;
	// 	a++;
	// }
} 

int	main(int argc, char **argv)
{
	t_list_a *list_a;

	if (argc == 1)
		return (0);
	ft_taking_list(argv, &list_a, argc);
}