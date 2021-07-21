#include "libft.h"

void	ft_lst2_move_up(t_list2 *lst)
{
	t_list2	*ptr;

	if (!lst)
		return ;
	if (lst->previous != NULL)
	{
		ptr = lst->next;
		lst->next = lst->previous;
		lst->previous = lst->previous->previous;
		lst->next->previous = lst;
		lst->next->next = ptr;
	}
}
