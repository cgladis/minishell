#include "libft.h"

void	ft_str_sort(char **str)
{
	int		fl;
	char	**ptr;
	char	*tmp;

	if (*str == NULL)
		return ;
	fl = 0;
	while (!fl)
	{
		fl = 1;
		ptr = str;
		while (*(ptr + 1))
		{
			if (ft_strcmp(*ptr, *(ptr + 1)) > 0)
			{
				tmp = *(ptr + 1);
				*(ptr + 1) = *ptr;
				*ptr = tmp;
				fl = 0;
			}
			ptr++;
		}
	}
}
