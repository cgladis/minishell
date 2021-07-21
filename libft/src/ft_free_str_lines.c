#include "libft.h"

void	ft_free_str_lines(char **str)
{
	char	**ptr;

	ptr = str;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(str);
}
