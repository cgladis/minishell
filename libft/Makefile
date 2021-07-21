NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
HFILENAME = ./src/libft.h

SRC_PATH = ./src/
OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NAME = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memmove.c ft_memset.c ft_strcmp.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_memcpy.c \
ft_strcpy.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_split.c\
ft_toupper.c ft_putchar.c ft_putnbr.c ft_power.c ft_print_n_char.c ft_lst2_move_up.c\
ft_max.c ft_putstr.c ft_free_str_lines.c ft_len_number.c ft_lstadd_back.c\
ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
ft_lstiter.c ft_lstlast.c ft_substr.c\
ft_lstnew.c ft_lstsize.c ft_union_lines.c\
ft_abs.c ft_strlcpy.c ft_strlcat.c\
ft_check_bit.c ft_cont_str.c ft_print.c\
get_next_line.c get_next_line_utils.c\
ft_add_str.c ft_get_float.c fr_get_simbol.c ft_len_lst2.c\
ft_lst2add_back.c ft_lst2add_front.c ft_lst2first.c \
ft_lst2last.c ft_lst2new.c ft_lst2clear.c ft_lst2delone.c ft_str_sort.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all:
	@$(MAKE) $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@printf  "\r%-25s\033[34m[$<]\033[0m\n" "libftprintf: $@"
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "\033[A\033[2K"

$(NAME): $(OBJ) $(HFILENAME)

	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "libft: $@"

bonus:		all

clean:
	@rm -rf $(OBJ_PATH)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "libft: $@"

fclean: clean
	@rm -f $(NAME)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "libft: $@"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re, bonus