#include "libft.h"

void	ft_lst2add_back(t_list2 **lst, t_list2 *new)
{
	t_list2	*ptr;

	if (lst && *lst && new)
	{
		ptr = ft_lst2last(*lst);
		ptr->next = new;
		new->previous = ptr;
	}
	else if (new)
		*lst = new;
}
