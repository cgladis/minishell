#include "minishell.h"

int	execute_command_env(char **argv, char **envp)
{
	int	i;

	(void)argv;
	(void)envp;
	i = 0;
	while (g_vars.envp[i] && ft_strchr(g_vars.envp[i], '='))
	{
		ft_putstr(g_vars.envp[i]);
		ft_putstr("\n");
		i++;
	}
	exit(0);
}
