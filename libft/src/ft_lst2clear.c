#include "libft.h"

void	ft_lst2clear(t_list2 *lst, void (*del)(void *))
{
	t_list2	*ptr;

	ptr = ft_lst2first(lst);
	while (ptr)
	{
		lst = ptr->next;
		ft_lst2delone(ptr, (*del));
		ptr = lst;
	}
}
