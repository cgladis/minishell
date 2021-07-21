#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"

typedef union u_ldouble
{
	long double		ld;
	struct			s_lbit
	{
		unsigned long long int	mantissa : 64;
		unsigned long int		exponent : 15;
		unsigned int			sign : 1;
	}				t_lbit;
}					t_ldouble;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_list2
{
	void			*content;
	struct s_list2	*next;
	struct s_list2	*previous;
}					t_list2;

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_calloc(size_t count, size_t size);

char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char *s, char const *separator);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_len(void **list);

/*
** ФУНКЦИИ РАБОТЫ СО СТРОКАМИ
*/

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_strcmp(const char *s1, const char *s2);

unsigned long long	ft_strlen(const char *s);

int					find_char(char const *search_string, char c);

char				*ft_strchr(const char *s, int c);

char				*ft_strstr(const char *s, const char *separator);

char				*ft_strrchr(const char *s, int c);

unsigned int		ft_len_number(unsigned int base, unsigned long long number);

char				*ft_strcut(char *s, char c);

char				*ft_strrcut(char *s, char c);

char				*ft_cont_str(char *str1, ...);

char				*ft_cont_str_and_free(char *str1, ...);

char				*ft_get_fill_str(unsigned int size, char c);

char				*ft_strcpy(char *dst, char *src);

char				**ft_union_lines(char **str1, char **str2);

void				ft_free_str_lines(char **str);

char				**ft_add_str(char **str1, char *str2);

char				**ft_add_str_and_free_str1(char **str1, char *str2);

char				**ft_add_str_and_free_str1_str2(char **str1, char *str2);

void				ft_str_sort(char **str);

/*
** ФУНКЦИИ РАБОТЫ С WCHAR
*/

unsigned long long	ft_strw_len(const wchar_t *s);

wchar_t				*ft_strw_dup(const wchar_t *s1);

size_t				ft_strw_lcpy(wchar_t *dst, const wchar_t *src,
						size_t dstsize);

char				*wstr_to_str(wchar_t *strw);

/*
** ФУНКЦИИ РАБОТЫ С ФАЙЛАМИ
*/

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

/*
** ФУНКЦИИ РАБОТЫ СО СПИСКАМИ
*/

t_list				*ft_lstnew(void *content);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstadd_front(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
** ФУНКЦИИ РАБОТЫ С ДВУСВЯЗНЫМИ СПИСКАМИ
*/

t_list2				*ft_lst2new(void *content);

t_list2				*ft_lst2last(t_list2 *lst);

t_list2				*ft_lst2first(t_list2 *lst);

void				ft_lst2add_back(t_list2 **lst, t_list2 *new);

void				ft_lst2add_front(t_list2 **lst, t_list2 *new);

void				ft_lst2delone(t_list2 *lst, void (*del)(void *));

void				ft_lst2clear(t_list2 *lst, void (*del)(void *));

int					ft_len_lst2(t_list2 *list);

void				ft_lst2_move_up(t_list2 *lst);

/*
** ФУНКЦИИ ВЫВОДА
*/

unsigned int		ft_putchar(char simbol);

unsigned int		ft_putstr(char *str);

unsigned int		ft_putnbr(long long nbr);

unsigned int		ft_put_hex_nbr(unsigned long long nbr);

unsigned int		ft_print_n_char(unsigned int n, char simbol);

int					ft_print(char *str1, ...);

int					ft_print_and_free(char *str1, ...);

char				*ft_get_hex_nbr(unsigned long long n);

char				*ft_get_nbr(unsigned long long nbr);

char				*ft_get_oct_nbr(unsigned long long n);

char				*ft_get_float(long double nbr, int precision);

char				*ft_get_exp(long double nbr, int precision,
						int round, int point);

/*
** МАТЕМАТИЧЕСКИЕ
*/

long long			ft_power(long long base, unsigned int power);

long				ft_max(long number1, long number2);

long double			ft_abs(long double nomber);

long double			ft_round(long double nbr, int kol);

/*
** БИТОВЫЕ
*/

int					ft_check_bit(double number, int position);

/*
** FT_PRINTF
*/

char				get_simbol(int n);

#endif
