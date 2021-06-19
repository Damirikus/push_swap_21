#include "push_swap.h"

void	ft_third_action(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	count = action->ra;
	while (count > 0)
	{
		ft_rt(stack_a, stack_b, 1);
		count--;
	}
	count = action->rrb;
	while (count > 0)
	{
		ft_rrtt(stack_a, stack_b, 2);
		count--;
	}
	ft_push(stack_b, stack_a, 2);
}

void	ft_fourth_action(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	count = action->rb;
	while (count > 0)
	{
		ft_rt(stack_a, stack_b, 2);
		count--;
	}
	count = action->rra;
	while (count > 0)
	{
		ft_rrtt(stack_a, stack_b, 1);
		count--;
	}
	ft_push(stack_b, stack_a, 2);
}
