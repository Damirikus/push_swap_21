#include "push_swap.h"

int	main(int argc, char **argv)
{
	css = 0;
	int		i;
	t_list	*stack_a;
	char	**massivforsplit;
	int		k;
	int		*massfororder;
	massfororder = (int *) malloc(sizeof(int) * 100000);
	if (!massfororder)
		ft_errors(1);
	ft_bzero(massfororder, 100000);
	i = 1;
	while (i < argc)
	{
		massivforsplit = ft_split(argv[i], ' ');
		k = 0;
		while (massivforsplit[k])
		{
			if (!ft_chek(massivforsplit[k], &stack_a))
				ft_errors(1);
			free(massivforsplit[k]);
			k++;
		}
		free(massivforsplit);
		i++;
	}
	if (!ft_distributor(&stack_a))
		ft_errors(1);
	ft_printf_a(&stack_a);
	printf("css = %d\n", css);
	return (0);
}

void	ft_errors(int a)
{
	(void)a;
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_distributor(t_list **stack_a)
{
	t_list	*stack_b;
	int		len;
	
	int		i;
	t_list	*current;

	current = *stack_a;
	len = ft_lstsize(*stack_a);
	
	ft_printf_a(stack_a);
	i = 0;
	while (current)
	{
		massfororder[i] = (int) current->content;
		i++;
		current = current->next;
	}
	massfororder[i] = '\0';

	if (ft_masscheck(massfororder, len))
		return (1);
		
	ft_disti(massfororder, stack_a, &stack_b, len);
	return (1);
}

void	ft_disti(int *massfororder, t_list **stack_a, t_list **stack_b, int len)
{
	
	sort_mass(massfororder, stack_a, len);
	if (len <= 5)
		ft_to_5(stack_a, stack_b, len);
	else
		ft_first(stack_a, stack_b);
	free(massfororder);
}

void	sort_mass(int *massfororder, t_list **stack_a, int len)
{
	int	i;
	int	j;
	int	temp;
		i = 0;											//печатаю массив для проверки
	while (i < len)
	{
		printf("mass = %d\n", massfororder[i]);
		i++;
	}
	i = 0;
	while (massfororder[i])
		i++;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - (i + 1))
		{
			if (massfororder[j] > massfororder[j + 1])
			{
				temp = massfororder[j];
				massfororder[j] = massfororder[j + 1];
				massfororder[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	init_orders(massfororder, stack_a, len);
}

void ft_printf_b(t_list **stack_b)
{
	t_list *current;
	current = *stack_b;
	while (current)
	{
		printf("ordB = %d ======== | | contB = %d\n", current->order, (int)current->content);
		current = current->next;
	}
}

void ft_printf_a(t_list **stack_a)
{
	t_list *current;
	current = *stack_a;
	while (current)
	{
		printf("order = %d ======== | | content = %d\n", current->order, (int)current->content);
		current = current->next;
	}
}
