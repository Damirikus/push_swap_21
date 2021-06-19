#include "push_swap.h"

void	ft_first(t_list **stack_a, t_list **stack_b)
{
	// t_flags	flags;
	// t_alg	action;
	(void)stack_b;
	(void)stack_a;
	// ft_zeroing(&flags, &action);
	// ft_find_begin_markup(stack_a, &flags);
	// ft_markuping(stack_a, &flags);
	// ft_push_b(stack_a, stack_b, flags.max_count_for_markup);
	// ft_main_algorithm(stack_a, stack_b, &action);
	// ft_traffic(stack_a);
}

void	ft_main_algorithm(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	t_list	*current;
	int		i;

	while (*stack_b)
	{
		current = *stack_b;
		action->len_stack_b = ft_len_stack(stack_b);
		action->max_order = 0;
		action->max_actions = 99999;
		i = 1;
		while (current)
		{
			action->rb = i - 1;
			if (action->rb != 0)
				action->rrb = action->len_stack_b - (i - 1);
			ft_find_order_stack_a(stack_a, action, current->order);
			ft_mooving_stack_a(stack_a, action);
			ft_parcing(action, current->order);
			current = current->next;
			i++;
		}
		ft_new_steps(stack_a, stack_b, action);
		ft_actions(stack_a, stack_b, action);
	}
}

void	ft_traffic(t_list **stack_a)
{
	t_list	*current;
	int		i;
	int		len;
	int		count;

	count = 0;
	len = ft_len_stack(stack_a);
	i = 1;
	current = *stack_a;
	while (current->order != 1)
	{
		i++;
		current = current->next;
	}
	if (i > (len / 2))
	{
		count = len - i + 1;
		while (count > 0)
		{
			ft_rrtt(stack_a, stack_a, 1);
			count--;
		}
	}
	else
		ft_traffic_helper(i, stack_a);
}

void	ft_traffic_helper(int i, t_list **stack_a)
{
	int	count;

	count = i - 1;
	while (count > 0)
	{
		ft_rt(stack_a, stack_a, 1);
		count--;
	}
}
