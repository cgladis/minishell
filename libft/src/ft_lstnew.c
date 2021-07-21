#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	if (item)
	{
		item->content = content;
		item->next = NULL;
		return (item);
	}
	return (NULL);
}
