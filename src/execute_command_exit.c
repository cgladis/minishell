#include "minishell.h"

int	check_c(char **argv, int c, int ret, int q)
{
	if (q > 1 && argv[1][c])
	{
		printf("numeric argument required\n");
		printf("exit\nlte-bash: exit: %s : ", argv[1]);
		ret = 2;
	}
	if (q > 1 && ret != 2)
		c = ft_atoi(argv[1]);
	c = ret;
	return (c);
}

int	execute_command_exit(char **argv, char **envp)
{
	int	c;
	int	q;
	int	ret;

	(void)envp;
	ret = 0;
	q = quanity_argv(argv);
	if (q > 2)
	{
		printf("exit\nlte-bash: exit: too many arguments\n");
		ret = 1;
	}
	else
	{
		c = 0;
		while (q > 1 && ft_isdigit(argv[1][c]))
			c++;
		c = check_c(argv, c, ret, q);
		exit(c);
	}
	return (0);
}
