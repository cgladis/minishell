#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include <unistd.h>
# include <term.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <signal.h>
# include <termios.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>

# define STDIN	0
# define STDOUT	1

typedef struct s_global
{
	int		exit_code;
	int		last_exit_status;
	int		like_term;
	char	**envp;
	char	**argv;
	char	**path;
	t_list2	*pipes;
	int		pipe_now;
	int		fd_in;
	int		fd_out;
	int		count_process;
	pid_t	ebash_pid;
	pid_t	current_pid;
	char	*pwd;
	char	*home;
	int		need_signal;
}	t_global;

typedef struct s_command
{
	int		command_number;
	char	**argv;
	char	*pwd;
	char	*env;
	char	*cache;
	int		redirect;
}	t_command;

int			entry_char_in_str(char c, char *str);

char		*del_first_chars_in_str(char *str, const char *chars);

char		*get_word(char **str, char *separator,
				char *stopsimbol, char *ignore);

char		*shift_str(char *str, int count);

int			execute_command(t_list2 **token);

int			execute_command_exit(char **argv, char **envp);

int			execute_command_echo(char **argv, char **envp);

int			execute_command_pwd(char **argv, char **envp);

int			execute_command_cd(char **argv, char **envp);

int			execute_command_env(char **argv, char **envp);

int			execute_command_export(char **argv, char **envp);

int			execute_command_unset(char **argv, char **envp);

t_list2		*get_token(char *prompt);

void		command_line(char **prompt, char *prefix);

void		rl_replace_line(const char *text, int clear_undo);

void		get_string(char *stop_world);

char		*my_readline(char *str, char *prefix);

char		*variable_value(char *var, char **envp);

char		*find_in_envp(char **envp, char *what);

int			quanity_argv(char **argv);

void		cd_way(char **argv);

void		cd_dot(char *argument);

void		wait_signal(int sign);

char		**get_path(char **envp);

t_global	get_vars(int argc, char **argv, char **envp);

int			no_fork(char **argv);

int			run_fork(void);

int			check_redirect(t_list2 **token);

void		run_pipes(void);

int			try_execve(char **path, char **command, char **envp);

int			check_pipe(t_list2 **token);

void		close_fd(void );

void		change_str(char **dst, char *str);

int			check_build_in(char **argv, char **envp);

int			run_programm(char **argv);

void		wait_signal_slash(int sign);

char		*get_name_env(char *str);

char		*get_value_env(char *str);

char		**record_envp(char **envp);

t_global	g_vars;

#endif
