#include "libft.h"

char	**get_last_str(char **str)
{
	while (*str)
		str++;
	return (str - 1);
}

int	ft_len(void **list)
{
	int	i;

	i = 0;
	while (*list)
	{
		i++;
		list++;
	}
	return (i);
}

char	**ft_add_str(char **str1, char *str2)
{
	char	**ptr;
	char	**new_list;

	if (str1 == NULL)
	{
		new_list = (char **) malloc(sizeof(char *) * 2);
		*new_list = ft_strdup(str2);
		*(new_list + 1) = NULL;
	}
	else
	{
		new_list = malloc(sizeof(char *) * (ft_len((void **)str1) + 2));
		if (!new_list)
			return (NULL);
		ptr = new_list;
		while (*str1)
		{
			*ptr = *str1;
			ptr++;
			str1++;
		}
		*ptr = ft_strdup(str2);
		*(ptr + 1) = NULL;
	}
	return (new_list);
}

char	**ft_add_str_and_free_str1(char **str1, char *str2)
{
	char	**new_list;

	new_list = ft_add_str(str1, str2);
	if (str1 != NULL)
		free(str1);
	return (new_list);
}

char	**ft_add_str_and_free_str1_str2(char **str1, char *str2)
{
	char	**new_list;

	new_list = ft_add_str(str1, str2);
	free(str1);
	free(str2);
	return (new_list);
}
