#include "push_swap.h"

void	ft_to_3(t_list **stack_a, int len)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = *stack_a;
	two = one->next;
	three = two->next;
	if (len == 2)
	{
		if (one->order > two->order)
			ft_swap(stack_a, stack_a, 1);
	}
	if (len == 3)
		ft_to_3_con(stack_a, one, two, three);
}

void	ft_to_3_con(t_list **stack_a, t_list *one, t_list *two, t_list *three)
{
	if (one->order > two->order && three->order > one->order)
		ft_swap(stack_a, stack_a, 1);
	else if (one->order < two->order && three->order < one->order)
		ft_rrtt(stack_a, stack_a, 1);
	else if (three->order > one->order && three->order < two->order)
	{
		ft_rrtt(stack_a, stack_a, 1);
		ft_swap(stack_a, stack_a, 1);
	}
	else if (three->order > two->order && three->order < one->order)
		ft_rt(stack_a, stack_a, 1);
	else if (two->order > three->order && two->order < one->order)
	{
		ft_swap(stack_a, stack_a, 1);
		ft_rrtt(stack_a, stack_a, 1);
	}
}

void	ft_zeroing(t_flags *flags, t_alg *action)
{
	action->len_stack_b = 0;
	action->len_stack_a = 0;
	action->max_order = 0;
	action->max_actions = 99999;
	action->rb = 0;
	action->rrb = 0;
	action->ra = 0;
	action->rra = 0;
	action->a_order_find = 0;
	action->rr1 = 0;
	action->rrr2 = 0;
	action->rarrb3 = 0;
	action->rbrra4 = 0;
	action->f = 0;
	action->min = 0;
	flags->count = 0;
	flags->max_count_for_markup = 0;
	flags->max_dig = 0;
	flags->max_markup_position = 0;
}
