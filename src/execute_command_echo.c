#include "minishell.h"

int	check_n(char *param)
{
	if (!ft_strncmp(param, "-n", 3))
		return (1);
	else
		return (0);
}

int	execute_command_echo(char **argv, char **envp)
{
	int	fl;

	(void)envp;
	if (ft_len((void **)argv) <= 1)
	{
		ft_print("\n", NULL);
		exit(0);
	}
	argv++;
	fl = check_n(*argv);
	if (fl)
		argv++;
	while (*argv)
	{
		ft_print(*argv, NULL);
		argv++;
		if (*argv != NULL)
			ft_print(" ", NULL);
	}
	if (!fl)
		ft_print("\n", NULL);
	exit(0);
}
