#include "minishell.h"

void	close_fd(void)
{
	int	*fd_current;

	if (g_vars.pipe_now != 3 && g_vars.pipe_now != 0)
	{
		fd_current = ft_lst2last(g_vars.pipes)->content;
		close(fd_current[1]);
	}
}
