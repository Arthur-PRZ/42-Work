
#include "../include/push_swap.h"

bool	sort_good(t_list **list_a)
{
	t_list	*temp;
	int		value;

	temp = *list_a;
	while(temp->next != NULL)
	{
		value = temp->nb;
		temp = temp->next;
		if (value > temp->nb)
			return (false);
	}
	return (true);
}

int		check_min(int nb, t_list *list, t_list **add_target)
{
	t_list	*bigger_value;
	t_list	*current;
	int		bigger_b;
	
	bigger_b = -1;
	bigger_value = NULL;
	current = list;
    while (current != NULL)
    {
        if (current->nb < nb)
            return 0;
        current = current->next;
    }
	while(list != NULL) 
	{
		if (list->nb > bigger_b && nb < list->nb)
		{
			bigger_b = list->nb;
			bigger_value = list;
		}
		list = list->next;
	}
    *add_target = bigger_value;
    return (1);
}

int	pc(int pos, int size)
{
	int	push_cost;
	int	mid_size;

	mid_size = size / 2;
	push_cost = 0;
	if (pos < mid_size || pos == mid_size)
		push_cost = pos;
	else if (pos > mid_size)
		push_cost = size - pos;
	return (push_cost);
}

int		check_both(int push_cost, t_list **list_b, t_list **list_a, t_list *current_a)
{
	int		size_b;
	int		size_a;
	int		pos_target_a;
	int		pos_target_b;

	pos_target_b = pos_target(*list_b, current_a->target);
	pos_target_a = pos_target(*list_a, current_a);
	size_b = ft_lstsize_ps(*list_b);
	size_a = ft_lstsize_ps(*list_a);
	if (pos_target_b <= size_b / 2 && pos_target_a <= size_a / 2 &&
		pos_target_b != 0 && pos_target_a != 0)
	{
		if (pos_target_b > pos_target_a)
			push_cost = push_cost - pos_target_a;
		else if (pos_target_b < pos_target_a)
			push_cost = push_cost - pos_target_b;
	}
	else if (pos_target_b >= size_b / 2 && pos_target_a >= size_a / 2 &&
		pos_target_b != size_b - 1 && pos_target_a != size_a - 1)
	{
		if (size_b - pos_target_b > size_a - pos_target_a)
			push_cost = push_cost - (size_a - pos_target_a);
		else if (size_b - pos_target_b < size_a - pos_target_a)
			push_cost = push_cost - (size_b - pos_target_b);
	}
	return (push_cost);
}

int		check_both_back(int push_cost, t_list **list_b, t_list **list_a, t_list *current_b)
{
	int		size_a;
	int		size_b;
	int		pos_target_a;
	int		pos_target_b;

	pos_target_a = pos_target(*list_a, current_b->target);
	pos_target_b = pos_target(*list_b, current_b);
	size_a = ft_lstsize_ps(*list_a);
	size_b = ft_lstsize_ps(*list_b);
	if (pos_target_b <= size_b / 2 && pos_target_a <= size_a / 2 &&
		pos_target_b != 0 && pos_target_a != 0)
	{
		if (pos_target_b > pos_target_a)
			push_cost = push_cost - pos_target_a;
		else if (pos_target_b < pos_target_a)
			push_cost = push_cost - pos_target_b;
	}
	else if (pos_target_b >= size_b / 2 && pos_target_a >= size_a / 2 &&
		pos_target_b != size_b - 1 && pos_target_a - 1 != size_a)
	{
		if (size_b - pos_target_b > size_a - pos_target_a)
			push_cost = push_cost - (size_a - pos_target_a);
		else if (size_b - pos_target_b < size_a - pos_target_a)
			push_cost = push_cost - (size_b - pos_target_b);
	}
	return (push_cost);
}
