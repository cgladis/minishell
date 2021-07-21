#include "libft.h"

char	*ft_cont_str(char *str1, ...)
{
	char	*result;
	char	*temp_str;
	va_list	arg_ptr;

	va_start(arg_ptr, str1);
	temp_str = ft_strdup("");
	while (str1 != NULL)
	{
		result = ft_strjoin(temp_str, str1);
		str1 = va_arg(arg_ptr, char *);
		free(temp_str);
		temp_str = result;
	}
	va_end(arg_ptr);
	return (result);
}

char	*ft_cont_str_and_free(char *str1, ...)
{
	char	*result;
	char	*temp_str;
	va_list	arg_ptr;

	va_start(arg_ptr, str1);
	temp_str = ft_strdup("");
	while (str1 != NULL)
	{
		result = ft_strjoin(temp_str, str1);
		free(str1);
		str1 = va_arg(arg_ptr, char *);
		free(temp_str);
		temp_str = result;
	}
	va_end(arg_ptr);
	return (result);
}
