#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		*lst = ptr->next;
		ft_lstdelone(ptr, (*del));
		ptr = *lst;
	}
}
