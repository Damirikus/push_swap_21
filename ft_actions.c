#include "push_swap.h"

void	ft_actions(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	if (action->ra >= action->rb)
		action->rr1 = action->ra;
	else
		action->rr1 = action->rb;
	if (action->rra >= action->rrb)
		action->rrr2 = action->rra;
	else
		action->rrr2 = action->rrb;
	action->rarrb3 = action->ra + action->rrb;
	action->rbrra4 = action->rb + action->rra;
	if (action->rr1 <= action->rrr2 && action->rr1 <= action->rarrb3 &&\
	action->rr1 <= action->rbrra4)
		ft_first_action(stack_a, stack_b, action);
	else if (action->rrr2 <= action->rr1 && action->rrr2 <= action->rarrb3 &&\
	action->rrr2 <= action->rbrra4)
		ft_second_action(stack_a, stack_b, action);
	else if (action->rarrb3 <= action->rr1 && action->rarrb3 <= action->rrr2 &&\
	action->rarrb3 <= action->rbrra4)
		ft_third_action(stack_a, stack_b, action);
	else if (action->rbrra4 <= action->rr1 && action->rbrra4 <= action->rrr2 &&\
	action->rbrra4 <= action->rarrb3)
		ft_fourth_action(stack_a, stack_b, action);
}

void	ft_first_action(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	if (action->ra >= action->rb)
	{
		count = action->rb;
		while (count > 0)
		{
			ft_rt(stack_a, stack_b, 0);
			count--;
		}
		count = action->ra - action->rb;
		if (count > 0)
		{
			while (count > 0)
			{
				ft_rt(stack_a, stack_b, 1);
				count--;
			}
		}
	}
	else
		ft_first_action_two(stack_a, stack_b, action);
	ft_push(stack_b, stack_a, 2);
}

void	ft_first_action_two(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	count = action->ra;
	while (count > 0)
	{
		ft_rt(stack_a, stack_b, 0);
		count--;
	}
	count = action->rb - action->ra;
	if (count > 0)
	{
		while (count > 0)
		{
			ft_rt(stack_a, stack_b, 2);
			count--;
		}
	}
}

void	ft_second_action(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	if (action->rra >= action->rrb)
	{
		count = action->rrb;
		while (count > 0)
		{
			ft_rrtt(stack_a, stack_b, 0);
			count--;
		}
		count = action->rra - action->rrb;
		if (count > 0)
		{
			while (count > 0)
			{
				ft_rrtt(stack_a, stack_b, 1);
				count--;
			}
		}
	}
	else
		ft_second_action_two(stack_a, stack_b, action);
	ft_push(stack_b, stack_a, 2);
}

void	ft_second_action_two(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	int	count;

	count = 0;
	count = action->rra;
	while (count > 0)
	{
		ft_rrtt(stack_a, stack_b, 0);
		count--;
	}
	count = action->rrb - action->rra;
	if (count > 0)
	{
		while (count > 0)
		{
			ft_rrtt(stack_a, stack_b, 2);
			count--;
		}
	}
}
