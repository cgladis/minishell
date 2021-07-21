#include "minishell.h"

char	*shift_str(char *str, int count)
{
	char	*result;

	result = strdup(str + count);
	free(str);
	return (result);
}

int	entry_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*del_first_chars_in_str(char *str, const char *chars)
{
	char	*ptr_str;
	char	*new_str;

	ptr_str = str;
	while (entry_char_in_str(*str, (char *)chars))
		str++;
	new_str = ft_strdup(str);
	free(ptr_str);
	return (new_str);
}

char	*get_word(char **str, char *separator, char *stopsimbol, char *ignore)
{
	char	*word;
	char	*start_str;
	char	*ptr_str;
	char	temp;

	ptr_str = del_first_chars_in_str(*str, separator);
	start_str = ptr_str;
	while (!entry_char_in_str(*ptr_str, separator)
		&& !entry_char_in_str(*ptr_str, stopsimbol) && *ptr_str)
		if (!entry_char_in_str(*ptr_str, ignore))
			ptr_str++;
	temp = *ptr_str;
	*ptr_str = '\0';
	word = ft_strdup(start_str);
	*ptr_str = temp;
	*str = ft_strdup(ptr_str);
	free(start_str);
	return (word);
}

int	run_fork(void)
{
	g_vars.current_pid = fork();
	if (g_vars.current_pid == 0)
	{
		if (g_vars.fd_in != STDIN)
		{
			dup2(g_vars.fd_in, STDIN);
			close(g_vars.fd_in);
		}
		if (g_vars.fd_out != STDOUT)
		{
			dup2(g_vars.fd_out, STDOUT);
			close(g_vars.fd_out);
		}
		run_pipes();
	}
	close_fd();
	return (g_vars.current_pid);
}
