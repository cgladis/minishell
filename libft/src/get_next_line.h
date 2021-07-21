#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int					get_next_line(int fd, char **line);

char				*ft_gnl_strjoin(char *s1, char *s2);

unsigned long long	ft_gnl_strlen(const char *s);

size_t				ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_gnl_strlcat(char *dst, const char *src, size_t dstsize);

void				*ft_gnl_memcpy(void *dst, const void *src, size_t n);

#endif
