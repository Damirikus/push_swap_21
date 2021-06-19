#include "push_swap.h"

void	ft_push_b(t_list **stack_a, t_list **stack_b, int len)
{
	t_list	*current;
	int		i;

	i = len + 1;
	while (i > len)
	{
		i = 0;
		if ((*stack_a)->flag == 0)
			ft_push(stack_a, stack_b, 1);
		else if ((*stack_a)->next->flag == 0)
			ft_swap(stack_a, stack_a, 1);
		else
			ft_rt(stack_a, stack_a, 1);
		current = *stack_a;
		while (current)
		{
			i++;
			current = current->next;
		}
	}
}

void	ft_markuping(t_list **stack_a, t_flags *flags)
{
	t_list	*current;
	t_list	*inner;

	current = *stack_a;
	while (current->order != flags->max_markup_position)
		current = current->next;
	current->flag = 1;
	flags->max_dig = current->order;
	inner = current;
	while (inner)
	{
		if (inner->order > flags->max_dig)
		{
			flags->max_dig = inner->order;
			inner->flag = 1;
		}
		inner = inner->next;
	}
	ft_markup_next(current->order, flags, stack_a);
}

void	ft_markup_next(int cur, t_flags *flags, t_list **stack_a)
{
	t_list	*inner;

	inner = *stack_a;
	while (inner->order != cur)
	{
		if (inner->order > flags->max_dig)
		{
			flags->max_dig = inner->order;
			inner->flag = 1;
		}
		inner = inner->next;
	}
}

void	ft_find_begin_markup(t_list **stack_a, t_flags *flags)
{
	t_list	*current;
	t_list	*inner;

	current = *stack_a;
	while (current)
	{
		flags->count = 0;
		flags->max_dig = current->order;
		flags->count++;
		inner = current;
		while (inner)
		{
			if (inner->order > flags->max_dig)
			{
				flags->max_dig = inner->order;
				flags->count++;
			}
			inner = inner->next;
		}
		ft_find_begin_markup_inner(stack_a, flags, current->order);
		current = current->next;
	}
}

void	ft_find_begin_markup_inner(t_list **stack_a, t_flags *flags, int cur)
{
	t_list	*inner;

	inner = *stack_a;
	while (inner->order != cur)
	{
		if (inner->order > flags->max_dig)
		{
			flags->max_dig = inner->order;
			flags->count++;
		}
		inner = inner->next;
	}
	if (flags->count > flags->max_count_for_markup)
	{
		flags->max_count_for_markup = flags->count;
		flags->max_markup_position = cur;
	}
}
