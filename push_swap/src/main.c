/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:23:10 by artperez          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:31 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**set_up_split(char **tab, t_list **list, char *str, char **argv)
{	
	tab = ft_split(argv[1], ' ');
	if (tab == NULL)
		exit (1);
	check_list(list, tab[0], tab);
	str = ft_itoa(ft_atoi(tab[0]));
	if (ft_same(tab[0], str) != true)
	{
		write(2, "Error\n", 6);
		free(str);
		exit (1);
	}
	free(str);
	*list = ft_lstnew_ps(ft_atoi(tab[0]));
	return (tab);
}
void	ft_taking_list_split(char **argv, t_list **list_a)
{
	int	a;
	char	**tab;
	char	*str;
	t_list	*new_node;
	
	a = 0;
	str = NULL;
	tab = NULL;
	tab = set_up_split(tab, list_a, str, argv);
	while (1)
	{
		a++;
		if (tab[a] == NULL)
			break ;
		check_list(list_a, tab[a], tab);
		str = ft_itoa(ft_atoi(tab[a]));
		if (ft_same(tab[a], str) != true)
			exit_error(list_a, tab, str);
		free(str);
		new_node = ft_lstnew_ps(ft_atoi(tab[a]));
		ft_lstadd_back_ps(list_a, new_node);
	}
	free_all(NULL, tab);
}

void set_up_taking(t_list **list, char **argv, char *str)
{
	check_list(list, argv[1], NULL);
	str = ft_itoa(ft_atoi(argv[1]));	
	if (ft_same(str, argv[1]) != true)
	{
		write(2, "Error\n", 6);
		free(str);
		exit (1);
	}
	*list = ft_lstnew_ps(ft_atoi(argv[1]));
	free(str);
}

void ft_taking_list(char **argv, t_list **list_a)
{
	int	a;
	char	*str;
	t_list	*new_node;
	
	a = 1;
	str = NULL;
	set_up_taking(list_a, argv, str);
	while (argv[a])
	{
		a++;
		if (argv[a] == NULL)
			break ;
		check_list(list_a, argv[a], NULL);
		str = ft_itoa(ft_atoi(argv[a]));	
		if (ft_same(str, str) != true)
			exit_error(list_a, NULL, str);
		free(str);
		new_node = ft_lstnew_ps(ft_atoi(argv[a]));
		ft_lstadd_back_ps(list_a, new_node);
	}
	check_duplicate(list_a, NULL);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		ft_taking_list_split(argv, &list_a);
	else
		ft_taking_list(argv, &list_a);
	if (sort_good(&list_a) == true || ft_lstsize_ps(list_a) == 1)
	{
		free_all(&list_a, NULL);
		return (1);
	}
	sort(&list_a, &list_b);
	// while (list_a != NULL)
	// {
	// 	printf("nb: %i\n", list_a->nb);
	// 	list_a = list_a->next;
	// }
	free_all(&list_a, NULL);
	return (1);
}
