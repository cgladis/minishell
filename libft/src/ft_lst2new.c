#include "libft.h"

t_list2	*ft_lst2new(void *content)
{
	t_list2	*item;

	item = (t_list2 *)malloc(sizeof(t_list2));
	if (item)
	{
		item->content = content;
		item->next = NULL;
		item->previous = NULL;
		return (item);
	}
	return (NULL);
}
