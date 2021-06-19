#include "push_swap.h"

void	ft_rrtt(t_list **stack_a, t_list **stack_b, int var)
{
	t_list	*current;
	t_list	*temp;

	if (var == 1 || var == 0)
	{
		current = *stack_a;
		if (current->next)
		{
			while (current->next)
			{
				if (!current->next->next)
					temp = current;
				current = current->next;
			}
			temp->next = NULL;
			current->next = *stack_a;
			*stack_a = current;
			if (var == 1)
				{write(1, "rra\n", 4);css++;}
		}
	}
	if (var == 2 || var == 0)
		ft_rrtt2(stack_b, temp, var);
}

void	ft_rrtt2(t_list **stack_b, t_list *temp, int var)
{
	t_list	*current;

	current = *stack_b;
	if (current->next)
	{
		while (current->next)
		{
			if (!current->next->next)
				temp = current;
			current = current->next;
		}
		temp->next = NULL;
		current->next = *stack_b;
		*stack_b = current;
	}
	if (var == 2)
		{write(1, "rrb\n", 4);css++;}
	if (var == 0)
		{write(1, "rrr\n", 4);css++;}
}
