#ifndef GET_TOKEN_H
# define GET_TOKEN_H

# include "minishell.h"

char	*check_slash_in_prompt(char **prompt);

char	*check_slash_in_prompt_like_term(char **prompt);

char	*variable_value(char *var, char **envp);

char	*check_slash_in_quote_support(char **prompt, char *c);

char	*check_slash_in_quote(char **prompt);

char	*check_slash_in_prompt(char **prompt);

char	*check_slash_in_prompt_like_term(char **prompt);

char	*check_slash_in_prompt_like_bash(char **prompt);

char	*one_quote(char **prompt);

char	*add_variable(char **prompt);

char	*double_quote(char **prompt);

char	*one_token(char **prompt);

#endif
