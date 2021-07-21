#include "minishell.h"

static void	cd_dot_while(char *my_oldpwd, char *my_pwd)
{
	int		i;
	char	*forfree;

	i = 0;
	while (g_vars.envp[i])
	{
		if (!ft_memcmp(g_vars.envp[i], "OLDPWD", ft_strlen("OLDPWD")))
		{
			forfree = g_vars.envp[i];
			g_vars.envp[i] = ft_cont_str("OLDPWD=", my_oldpwd, NULL);
			free(forfree);
		}
		if (!ft_memcmp(g_vars.envp[i], "PWD", ft_strlen("PWD")))
		{
			forfree = g_vars.envp[i];
			g_vars.envp[i] = ft_cont_str("PWD=", my_pwd, NULL);
			chdir(my_pwd);
			free(forfree);
		}
		i++;
	}
}

void	cd_dot(char *argument)
{
	int		len;
	char	*my_pwd;
	char	*my_oldpwd;

	my_pwd = find_in_envp(g_vars.envp, "PWD");
	my_oldpwd = ft_strdup(my_pwd);
	if (argument[1] == '.')
	{
		len = ft_strlen(my_pwd);
		if (len > 1 && my_pwd[len - 1] == '/')
			my_pwd[len - 1] = '\0';
		while (my_pwd[len] != '/')
			len--;
		if (len != 0)
			my_pwd[len] = '\0';
		else if (len == 0)
		{
			my_pwd[0] = '/';
			my_pwd[1] = '\0';
		}
		cd_dot_while(my_oldpwd, my_pwd);
	}
	free(my_oldpwd);
}

int	execute_command_cd(char **argv, char **envp)
{
	(void)envp;
	if (!g_vars.envp)
		return (0);
	if (!find_in_envp(g_vars.envp, "PWD"))
		g_vars.envp = ft_add_str_and_free_str1_str2(g_vars.envp,
				ft_cont_str("PWD=", g_vars.pwd, NULL));
	if (ft_len((void **)argv) == 1)
		cd_way(argv);
	else
	{
		if (argv[1][0] == '.')
			cd_dot(argv[1]);
		else if (argv[1][0] == '/' || ft_isprint(argv[1][0]))
			cd_way(argv);
		else
			if (argv[1][0] != '\0')
				printf("lte-bash: cd: %s: No such file or directory\n", argv[1]);
	}
	return (0);
}
