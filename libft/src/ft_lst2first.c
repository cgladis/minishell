#include "libft.h"

t_list2	*ft_lst2first(t_list2 *lst)
{
	if (!lst)
		return (NULL);
	while (lst->previous != NULL)
	{
		lst = lst->previous;
	}
	return (lst);
}
