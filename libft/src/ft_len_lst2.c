#include "libft.h"

int	ft_len_lst2(t_list2 *list)
{
	t_list2	*current_lst;
	int		i;

	if (list == NULL)
		return (0);
	current_lst = ft_lst2first(list);
	i = 0;
	while (current_lst)
	{
		i++;
		current_lst = current_lst->next;
	}
	return (i);
}
