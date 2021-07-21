#include "minishell.h"
#include <stdio.h>

void	its_ctrl_d(void)
{
	ft_putstr("\033[A");
	ft_putstr("lte-bash> exit\n");
	exit(0);
}

char	*my_readline(char *str, char *prefix)
{
	char	*ret;

	g_vars.need_signal = 1;
	ret = readline(prefix);
	ret = ft_cont_str_and_free(str, ret, NULL);
	g_vars.need_signal = 0;
	return (ret);
}

void	command_line(char **prompt, char *prefix)
{
	char	*to_history;

	*prompt = readline(prefix);
	if (!(*prompt))
		its_ctrl_d();
	to_history = ft_strdup(*prompt);
	if (*prompt && **prompt)
	{
		if (!strncmp(*prompt, "echo", 4))
		{
			to_history[ft_strlen(to_history)] = '\0';
			add_history(to_history);
			rl_on_new_line();
		}
		else
			add_history(*prompt);
	}
	free(to_history);
}
