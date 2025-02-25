
#include "../include/push_swap.h"


void	sort_3(t_list **list_a)
{
	t_list *current;
	t_list *last_node;
	int		bigger_value;
	
	if (sort_good(list_a))
		return;
	current = *list_a;
	if (current->nb > current->next->nb && current->nb > current->next->next->nb)
		sa(list_a);
	current = *list_a;
	if (current->next->nb > current->next->next->nb)
		ra(list_a);
	current = *list_a;
	if (current->nb > current->next->nb)
		sa(list_a);
}

void	target(t_list **list_a, t_list **list_b)
{
	t_list *temp_a;
	t_list *temp_b;
	int		smaller_value;
	
	temp_a = *list_a;
	while (temp_a != NULL)
	{
		temp_b = *list_b;
		smaller_value = temp_b->nb;
		while (temp_a != NULL && check_min(temp_a->nb, temp_b, &(temp_a->target)) == 1 && temp_a != NULL)
		 	temp_a = temp_a->next;
		while (temp_b != NULL)
		{
			if (temp_a->nb > temp_b->nb 
				&& smaller_value > temp_a->nb - temp_b->nb)
			{
				smaller_value = temp_a->nb - temp_b->nb;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (temp_a != NULL)
			temp_a = temp_a->next;
	}
}

void	add_cheapest(t_list **list_a, t_list **list_b)
{
	t_list	*current_a;
	t_list	*push_node;
	int		smaller_pc;

	current_a = *list_a;
	push_node = *list_a;
	while (current_a != NULL)
	{
		smaller_pc = current_a->push_cost;
		if (smaller_pc == 1)
		{
			add_b(push_node, list_b, list_a);
			return ;
		}
		if (smaller_pc > current_a->push_cost)
		{
			smaller_pc = current_a->push_cost;
			push_node = current_a;
		}
		current_a = current_a->next;
	}
	add_b(push_node, list_b, list_a);
}