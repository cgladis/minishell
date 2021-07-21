#include "minishell.h"

char	*find_in_envp(char **envp, char *what)
{
	int		c;
	int		len;
	char	*cache;

	if (g_vars.envp == NULL)
		return (NULL);
	what = ft_cont_str(what, "=", NULL);
	len = strlen(what);
	c = 0;
	while (envp[c] && ft_memcmp(what, envp[c], len))
		c++;
	if (envp[c])
		cache = envp[c] + len;
	else
		cache = NULL;
	free(what);
	return (cache);
}

int	quanity_argv(char **argv)
{
	int	c;

	c = 0;
	if (!argv)
		return (0);
	while (argv[c])
		c++;
	return (c);
}

void	wait_signal(int sign)
{
	if (sign == SIGINT)
	{
		if (g_vars.current_pid == 0 || g_vars.current_pid == g_vars.ebash_pid)
		{
			ft_putstr("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else
			ft_putstr("^C\n");
	}
}

void	wait_signal_slash(int sign)
{
	if (sign == SIGQUIT)
	{
		if (g_vars.current_pid == 0 || g_vars.current_pid == g_vars.ebash_pid)
		{
			rl_on_new_line();
			rl_redisplay();
		}
		else
			ft_putstr("^\\Quit: 3\n");
	}
}

void	*write_error(char *prefix, char *str_error)
{
	write(1, prefix, ft_strlen(prefix));
	write(1, str_error, ft_strlen(str_error));
	write(1, "\n", 1);
	free(str_error);
	return (NULL);
}
