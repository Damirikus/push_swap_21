#include "push_swap.h"

void	ft_to_5(t_list **stack_a, t_list **stack_b, int len)
{
	int	res;
	int	position_min;

	while (len > 3)
	{
		position_min = ft_position_min(stack_a, ft_minimum(stack_a));
		res = (len / 2) - position_min;
		upordown(stack_a, position_min, res);
		ft_push(stack_a, stack_b, 1);
		len--;
	}
	ft_to_3(stack_a, len);
	res = ft_lstsize(*stack_b);
	while (res > 0)
	{
		ft_push(stack_b, stack_a, 2);
		res--;
	}
}

void	upordown(t_list **stack_a, int position_min, int res)
{
	if (res >= 0)
	{
		while (position_min != 1)
		{
			ft_rt(stack_a, stack_a, 1);
			position_min = ft_position_min(stack_a, ft_minimum(stack_a));
		}
	}
	else
	{
		while (position_min != 1)
		{
			ft_rrtt(stack_a, stack_a, 1);
			position_min = ft_position_min(stack_a, ft_minimum(stack_a));
		}
	}
}

int	ft_minimum(t_list **stack_a)
{
	t_list	*current;
	int		min;

	current = *stack_a;
	min = (int)(*stack_a)->content;
	while (current)
	{
		if ((int)current->content < min)
			min = (int) current->content;
		current = current->next;
	}
	return (min);
}

int	ft_position_min(t_list **stack_a, int min)
{
	int		i;
	t_list	*current;

	i = 1;
	current = *stack_a;
	while ((int) current->content != min)
	{
		i++;
		current = current->next;
	}
	return (i);
}
