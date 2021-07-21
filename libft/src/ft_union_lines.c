#include "libft.h"

char	**ft_union_lines(char **str1, char **str2)
{
	char	**res;
	char	**ptr;
	char	**ptr_tmp;

	res = (char **)malloc((ft_len((void **)str1) + ft_len((void **)str2) + 1)
			* sizeof(char *));
	ptr = res;
	ptr_tmp = str1;
	while (*ptr_tmp)
	{
		*ptr = *ptr_tmp;
		ptr++;
		ptr_tmp++;
	}
	free(str1);
	ptr_tmp = str2;
	while (*ptr_tmp)
	{
		*ptr = *ptr_tmp;
		ptr++;
		ptr_tmp++;
	}
	free(str2);
	*ptr = NULL;
	return (res);
}
