#include "minishell.h"

int	redir_one_out(t_list2 *current_token, int fd)
{
	if (!ft_strncmp(current_token->content, ">", 2))
	{
		fd = open(current_token->next->content,
				  O_CREAT | O_WRONLY | O_TRUNC, 00777);
		if (fd == -1)
			return (-1);
		if (g_vars.fd_out != STDOUT)
			close(g_vars.fd_out);
		g_vars.fd_out = fd;
	}
	return (fd);
}

int	redir_double_out(t_list2 *current_token, int fd)
{
	if (!ft_strncmp(current_token->content, ">>", 3))
	{
		fd = open(current_token->next->content,
				  O_CREAT | O_WRONLY | O_APPEND, 00777);
		if (fd == -1)
			return (-1);
		if (g_vars.fd_out != STDOUT)
			close(g_vars.fd_out);
		g_vars.fd_out = fd;
	}
	return (fd);
}

int	redir_one_in(t_list2 *current_token, int fd)
{
	if (!ft_strncmp(current_token->content, "<", 2))
	{
		fd = open(current_token->next->content, O_RDONLY);
		if (fd == -1)
			return (-1);
		if (g_vars.fd_in != STDIN)
			close(g_vars.fd_in);
		g_vars.fd_in = fd;
	}
	return (fd);
}

int	redir_double_in(t_list2 *current_token, int fd)
{
	if (!ft_strncmp(current_token->content, "<<", 3))
	{
		get_string(current_token->next->content);
		fd = open(".tmp", O_RDONLY);
		if (fd == -1)
			return (-1);
		if (g_vars.fd_in != STDIN)
			close(g_vars.fd_in);
		g_vars.fd_in = fd;
	}
	return (fd);
}

int	check_redirect(t_list2 **token)
{
	int		fd;
	t_list2	*current_token;

	fd = 0;
	current_token = *token;
	if (current_token->next == NULL
		&& (!ft_strncmp(current_token->content, ">", 2)
			|| !ft_strncmp(current_token->content, ">>", 3)
			|| !ft_strncmp(current_token->content, "<", 2)
			|| !ft_strncmp(current_token->content, "<<", 3)))
	{
		ft_print("parse error near `\\n'", NULL);
		return (-1);
	}
	fd = redir_one_out(current_token, fd);
	fd = redir_double_out(current_token, fd);
	fd = redir_one_in(current_token, fd);
	fd = redir_double_in(current_token, fd);
	if (fd == -1)
		return (-1);
	if (fd != 0)
		*token = current_token->next->next;
	return (fd);
}
