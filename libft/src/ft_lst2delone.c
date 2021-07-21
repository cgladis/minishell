#include "libft.h"

void	ft_lst2delone(t_list2 *lst, void (*del)(void *))
{
	t_list2	*ptr;

	if (lst == NULL)
		return ;
	if (lst->previous)
	{
		ptr = lst->previous;
		ptr->next = lst->next;
	}
	if (lst->next)
	{
		ptr = lst->next;
		ptr->previous = lst->previous;
	}
	(*del)(lst->content);
	free(lst);
}
