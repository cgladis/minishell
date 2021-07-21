#include "libft.h"

void	ft_lst2add_front(t_list2 **lst, t_list2 *new)
{
	t_list2	*ptr;

	if (lst && new)
	{
		ptr = ft_lst2first(*lst);
		ptr->previous = new;
		new->next = ptr;
	}
	else if (new)
		*lst = new;
}
