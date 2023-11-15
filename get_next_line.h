#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

// #define MAX_FD 1024

char		*get_next_line(int fd);
char		*ft_strcat_and_copy(char *dest, const char *src, int is_copy);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_findstrind(const char *s, int c);
void		ft_strdel(char **as);
int			ft_new_line(char **s, char **line, int result);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);

#endif