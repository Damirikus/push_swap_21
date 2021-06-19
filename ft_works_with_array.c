#include "push_swap.h"

void	init_orders(int *massfororder, t_list **stack_a, int len)
{
	t_list	*current;
	int		i;

	i = 0;
	while (i < len)
	{
		current = *stack_a;
		while ((int) current->content != massfororder[i])
			current = current->next;
		current->order = i + 1;
		i++;
	}
}

int	ft_masscheck(int *massfororder, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (massfororder[i - 1] > massfororder[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_init(t_list **stack_a, long cont)
{
	t_list	*new;

	new = ft_lstnew((void *) cont);
	if (!ft_lstadd_back(stack_a, new))
		return (0);
	return (1);
}

int	ft_chek(char *str, t_list **stack_a)
{
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	if (str[i] == 45 || str[i] == 43)
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (!ft_check_max_min(str))
		return (0);
	nb = ft_atoi(str);
	if (!ft_init(stack_a, nb))
		return (0);
	return (1);
}

int	ft_check_max_min(char *str)
{
	char	*buf;
	int		i;

	i = 0;
	if (ft_strlen(str) < 10)
		return (1);
	if (str[i] == 45)
		i++;
	if (i == 1)
	{
		buf = "2147483648";
		if (ft_strncmp(buf, str + 1, 10) < 0)
			return (0);
	}
	else
	{
		buf = "2147483647";
		if (ft_strncmp(buf, str, 10) < 0)
			return (0);
	}
	return (1);
}
