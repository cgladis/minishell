#include "libft.h"

int	ft_print(char *str1, ...)
{
	int		count;
	int		current_count;
	va_list	arg_ptr;

	count = 0;
	va_start(arg_ptr, str1);
	while (str1 != NULL)
	{
		current_count = ft_strlen(str1);
		count += current_count;
		write(1, str1, current_count);
		str1 = va_arg(arg_ptr, char *);
	}
	va_end(arg_ptr);
	return (count);
}

int	ft_print_and_free(char *str1, ...)
{
	int		count;
	int		current_count;
	va_list	arg_ptr;

	count = 0;
	va_start(arg_ptr, str1);
	while (str1 != NULL)
	{
		current_count = ft_strlen(str1);
		count += current_count;
		write(1, str1, current_count);
		free(str1);
		str1 = va_arg(arg_ptr, char *);
	}
	va_end(arg_ptr);
	return (count);
}
