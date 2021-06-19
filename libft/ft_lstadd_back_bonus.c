#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!new)
		return (0);
	if (*lst)
	{
		if (current->content == new->content)
			return (0);
		while (current->next)
		{
			if (current->content == new->content)
				return (0);
			current = current->next;
		}
		current->next = new;
		if (current->content == new->content)
			return (0);
	}
	else
		*lst = new;
	return (1);
}
