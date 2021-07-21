#include "minishell.h"

static void	cd_way_without_slash(char **argv, char *cache, int i, int len)
{
	if (argv[1][len - 1] == '/' && len != 1)
		argv[1][len - 1] = '\0';
	if (ft_strlen(cache) == 1)
		cache[0] = '\0';
	if (argv[1][ft_strlen(argv[1]) - 1] == '/')
		g_vars.envp[i] = ft_cont_str("PWD=", cache, argv[1], NULL);
	else
		g_vars.envp[i] = ft_cont_str("PWD=", cache, "/", argv[1], NULL);
}

static void	cd_way_with_slash(char **argv, int i, int len)
{
	if (argv[1][1] == '.')
		g_vars.envp[i] = ft_cont_str("PWD=", "/", NULL);
	else
	{
		if (argv[1][len - 1] == '/' && len != 1)
			argv[1][len - 1] = '\0';
		g_vars.envp[i] = ft_cont_str("PWD=", argv[1], NULL);
	}
}

static void	cd_way_with_arg(char **argv, char *cache, int i)
{
	char	*forfree;
	int		len;

	len = ft_strlen(argv[1]);
	while (g_vars.envp[i])
	{
		if (!ft_memcmp(g_vars.envp[i], "PWD", ft_strlen("PWD")))
		{
			forfree = g_vars.envp[i];
			if (argv[1][0] == '/')
				cd_way_with_slash(argv, i, len);
			else
				cd_way_without_slash(argv, cache, i, len);
			free(forfree);
		}
		i++;
		chdir(argv[1]);
	}
}

static void	cd_way_without_arg(int i)
{
	char	*cache;

	cache = find_in_envp(g_vars.envp, "HOME");
	while (g_vars.envp[i])
	{
		if (!ft_memcmp(g_vars.envp[i], "PWD", ft_strlen("PWD")))
		{
			free(g_vars.envp[i]);
			g_vars.envp[i] = ft_cont_str("PWD=", cache, NULL);
			chdir(cache);
		}
		i++;
	}
}

void	cd_way(char **argv)
{
	char		*cache;
	int			fd;

	cache = find_in_envp(g_vars.envp, "PWD");
	if (ft_len((void **)argv) == 1)
		cd_way_without_arg(0);
	else
	{
		fd = chdir(argv[1]);
		if (fd != 0)
			printf("bash: cd: %s: No such file or directory\n", argv[1]);
		else
			cd_way_with_arg(argv, cache, 0);
	}
}
