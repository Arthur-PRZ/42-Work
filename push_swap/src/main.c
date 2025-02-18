/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:23:10 by artperez          #+#    #+#             */
/*   Updated: 2025/02/18 11:40:28 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_taking_list(char **argv, t_list **list_a, int argc)
{
	int	a;
	char	**tab;
	t_list	*new_node;
	
	a = 0;
	tab = NULL;
	if (argc == 2)
	{
		while (argc == 2)
		{
			if (a == 0)
			{
				tab = ft_split(argv[1], ' ');
				if (tab == NULL)
					return ;
				*list_a = ft_lstnew_ps(ft_atoi(tab[0]));
			}
			check_list(list_a, tab[a], tab);
			a++;
			if (tab[a] == NULL)
				break ;
			new_node = ft_lstnew_ps(ft_atoi(tab[a]));
			ft_lstadd_back_ps(list_a, new_node);
		}
	}
	if (argc != 2)
		a = 1;
	if (argc != 2)
	{
		while (argv[a])
		{
			if (a == 1)
			{
				check_list(list_a, argv[a], NULL);
	 			*list_a = ft_lstnew_ps(ft_atoi(argv[1]));
			}
			a++;
			if (argv[a] == NULL)
				break ;
			check_list(list_a, argv[a], NULL);
			new_node = ft_lstnew_ps(ft_atoi(argv[a]));
			ft_lstadd_back_ps(list_a, new_node);
		}
	}
	check_duplicate(list_a, tab);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	// list_b = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	ft_taking_list(argv, &list_a, argc);
	if (sort_good(&list_a) == 0)
		return (1);
	sort(&list_a, &list_b);
	printf("%d", list_a->nb);
}