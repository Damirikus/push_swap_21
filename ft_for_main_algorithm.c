#include "push_swap.h"

void	ft_new_steps(t_list **stack_a, t_list **stack_b, t_alg *action)
{
	t_list	*current;
	int		len_b;
	int		i;

	i = 1;
	len_b = ft_len_stack(stack_b);
	current = *stack_b;
	while (current->order != action->max_order)
	{
		current = current->next;
		i++;
	}
	action->rb = i - 1;
	action->rrb = len_b - (i - 1);
	ft_find_order_stack_a(stack_a, action, action->max_order);
	ft_mooving_stack_a(stack_a, action);
}

void	ft_parcing(t_alg *action, int ord)
{
	int	min_act;
    min_act = 0;
	if (action->ra >= action->rb)
		min_act = action->ra;
	else
		min_act = action->rb;
	if (action->rra >= action->rrb)
	{
		if (action->rra < min_act)
			min_act = action->rra;
	}
	else
	{
		if (action->rrb < min_act)
			min_act = action->rrb;
	}
	if (action->ra + action->rrb < min_act)
		min_act = action->ra + action->rrb;
	if (action->rra + action->rb < min_act)
		min_act = action->ra + action->rrb;
	if (min_act < action->max_actions)
	{
		action->max_actions = min_act;
		action->max_order = ord;
	}
}

void	ft_find_order_stack_a(t_list **stack_a, t_alg *action, int ord)
{
	t_list	*current;
	t_list	*inner;
	int		i;
	int		min;
	int     f;
	f = 0;
    min = 0;
	current = *stack_a;
	min = ord;
	i = 1;
	while (current)
	{
		min = ord + i;
		inner = *stack_a;
		while (inner)
		{
			if (inner->order == min)
			{
				action->a_order_find = inner->order;
				f++;
				break ;
			}
			inner = inner->next;
		}
		if (f == 1)
			break ;
		i++;
	}
}

void	ft_mooving_stack_a(t_list **stack_a, t_alg *action)
{
	t_list	*current;
	int		i;

	i = 1;
	current = *stack_a;
	action->len_stack_a = ft_len_stack(stack_a);
	while (current->order != action->a_order_find)
	{
		i++;
		current = current->next;
	}
	action->ra = i - 1;
	if (action->ra != 0)
		action->rra = action->len_stack_a - (i - 1);
}

int	ft_len_stack(t_list **stack)
{
	t_list	*cur;
	int		len;

	len = 0;
	cur = *stack;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
