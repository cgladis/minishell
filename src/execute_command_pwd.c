#include "minishell.h"

int	execute_command_pwd(char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	if (!find_in_envp(g_vars.envp, "PWD") && g_vars.envp)
		g_vars.envp = ft_add_str_and_free_str1_str2(g_vars.envp,
				ft_cont_str("PWD=", g_vars.pwd, NULL));
	if (find_in_envp(g_vars.envp, "PWD"))
		printf("%s\n", find_in_envp(g_vars.envp, "PWD"));
	else
		printf("%s\n", g_vars.pwd);
	exit(0);
}
