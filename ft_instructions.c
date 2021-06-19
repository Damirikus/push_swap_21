#include "push_swap.h"

void	ft_swap(t_list **stack_a, t_list **stack_b, int var)
{
	t_list	*current;
	t_list	*third;

	if (var == 1 || var == 0)
	{
		current = *stack_a;
		if (current->next)
		{
			*stack_a = (*stack_a)->next;
			third = (*stack_a)->next;
			current->next = third;
			(*stack_a)->next = current;
			if (var == 1)
				{write(1, "sa\n", 3);css++;}
		}
	}
	if (var == 2 || var == 0)
	{
		ft_swap2(stack_b, third);
		if (var == 2)
			{write(1, "sb\n", 3);css++;}
	}
	if (var == 0)
		{write(1, "ss\n", 3);css++;}
}

void	ft_swap2(t_list **stack_b, t_list *third)
{
	t_list	*current;

	current = *stack_b;
	if (current->next)
	{
		*stack_b = (*stack_b)->next;
		third = (*stack_b)->next;
		current->next = third;
		(*stack_b)->next = current;
	}
}

void	ft_push(t_list **stack_a, t_list **stack_b, int var)
{
	t_list	*current;

	if (stack_a)
	{
		current = *stack_a;
		*stack_a = (*stack_a)->next;
		current->next = *stack_b;
		*stack_b = current;
		if (var == 1)
			{write(1, "pb\n", 3);css++;}
		else if (var == 2)
			{write(1, "pa\n", 3);css++;}
	}
}

void	ft_rt(t_list **stack_a, t_list **stack_b, int var)
{
	t_list	*current;
	t_list	*temp;

	if (var == 1 || var == 0)
	{
		current = *stack_a;
		if (current->next)
		{
			*stack_a = (*stack_a)->next;
			current->next = NULL;
			temp = *stack_a;
			while (temp->next)
				temp = temp->next;
			temp->next = current;
			if (var == 1)
				{write(1, "ra\n", 3);css++;}
		}
	}
	if (var == 2 || var == 0)
		ft_rt2(stack_b, temp, var);
}

void	ft_rt2(t_list **stack_b, t_list *temp, int var)
{
	t_list	*current;

	current = *stack_b;
	if (current->next)
	{
		*stack_b = (*stack_b)->next;
		current->next = NULL;
		temp = *stack_b;
		while (temp->next)
			temp = temp->next;
		temp->next = current;
	}
	if (var == 2)
		{write(1, "rb\n", 3);css++;}
	if (var == 0)
		{write(1, "rr\n", 3);css++;}
}
