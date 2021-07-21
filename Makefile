NAME = minishell
LIBFT_NAME = libft.a
MAIN_NAME = minishell.c
HFILENAME = ./src/minishell.h

SRC_NAME = minishell.c interactive_command_line.c \
			execute_command_cd.c execute_command_echo.c \
			execute_command_env.c execute_command_export.c \
			execute_command_pwd.c execute_command_unset.c \
			execute_command_exit.c execute_command.c \
			execute_command_support_functions.c get_token.c \
			commands_add_func.c get_string_gnl.c \
			execute_command_cd_way.c commands_add_func2.c \
			get_token_add.c get_token_add2.c execute_command1.c\
			execute_command_check.c execute_command_add_func2.c \
			execute_command_add_func.c execute_command_support_functions1.c \
			execute_command_export1.c

CC = gcc

LIB_PATH = ./libft/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

FLAGS = -Wall -Wextra -Werror -g

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_BONUS_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBFT = $(addprefix $(LIB_PATH), $(LIBFT_NAME))
ARC_86_64 = x86_64
ARC_ARM = arm64

PROC_V = $(shell uname -m)

ifeq ($(PROC_V), $(ARC_ARM))
	READLINE_LIB = -lreadline -lcurses -L/opt/homebrew/Cellar/readline/8.1/lib
	READLINE_INC = -I/opt/homebrew/Cellar/readline/8.1/include
else ifeq ($(PROC_V), $(ARC_86_64))
	READLINE_LIB = -lreadline -lcurses -L/Users/$(LOGNAME)/.brew/Cellar/readline/8.1/lib
	READLINE_INC = -I/Users/$(LOGNAME)/.brew/Cellar/readline/8.1/include
else
	READLINE_LIB = -lreadline -lcurses -L/Users/$(LOGNAME)/.brew/Cellar/readline/8.1/lib
	READLINE_INC = -I/Users/$(LOGNAME)/.brew/Cellar/readline/8.1/include
endif

all:

#	@brew install readline

#	@echo $(PROC_V)
#	@echo $(READLINE_LIB)
#	@echo $(READLINE_INC)
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c

	@mkdir -p $(OBJ_PATH)
	@printf  "\r%-25s\033[34m[$<]\033[0m\n" "minishell: $@"
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "\033[A\033[2K"

$(NAME): $(OBJ) $(HFILENAME) $(LIBFT)

	@$(CC) $(FLAGS) $(LIBFT) $(OBJ) $(READLINE_LIB) $(READLINE_INC) -o $(NAME)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "minishell: $@"

bonus: all

run: all

	@./minishell

leaks: all

	@valgrind ./minishell --leak-check=full

clean:

	@$(MAKE) -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "minishell: $@"


fclean: clean

	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -rf $(NAME)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "minishell: $@"

re: fclean all

.PHONY: clean fclean re bonus run
