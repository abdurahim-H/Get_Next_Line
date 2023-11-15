#include "get_next_line.h"

int	ft_findstrind(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

int	ft_new_line(char **s, char **line, int result)
{
	char	*temp;
	int		str_end;

	str_end = ft_findstrind(*s, '\n');
	if ((str_end) != -1)
	{
		*line = ft_substr(*s, 0, str_end + 1);
		temp = ft_strdup(&(*s)[str_end + 1]);
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else if (result == 0)
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

char	*read_from_file(int fd, char *s, int *result)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	*result = 0;
	if (ft_findstrind(s, '\n') == -1)
	{
		while (1)
		{
			*result = read(fd, buffer, BUFFER_SIZE);
			if (*result <= 0)
				break ;
			buffer[*result] = '\0';
			if (s == NULL)
				s = ft_strdup(buffer);
			else
			{
				temp = ft_strjoin(s, buffer);
				free(s);
				s = temp;
			}
			if (ft_findstrind(buffer, '\n') > -1)
				break ;
		}
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s = NULL;
	char		*line;
	int			result;

	result = 0;
	s = read_from_file(fd, s, &result);
	if (result < 0)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	else if (result == 0 && s == NULL && ft_findstrind(s, '\n') == -1)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	else
		if (ft_new_line(&s, &line, result) == 1
			|| (result == 0 && line != NULL))
			return (line);
	free(s);
	s = NULL;
	return (NULL);
}

// char	*read_from_fd(int fd, char *s, int *result)
// {
// 	s = read_from_file(fd, s, result);
// 	if (*result < 0)
// 	{
// 		free(s);
// 		s = NULL;
// 	}
// 	return (s);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*s[MAX_FD];
// 	char		*line;
// 	int			result;

// 	if (fd < 0 || fd >= MAX_FD)
// 		return (NULL);
// 	result = 0;
// 	s[fd] = read_from_fd(fd, s[fd], &result);
// 	if (s[fd] == NULL)
// 		return (NULL);
// 	else if (result == 0 && s[fd] == NULL && ft_findstrind(s[fd], '\n') == -1)
// 	{
// 		free(s[fd]);
// 		s[fd] = NULL;
// 		return (NULL);
// 	}
// 	else
// 		if (ft_new_line(&s[fd], &line, result) == 1
// 			|| (result == 0 && line != NULL))
// 			return (line);
// 	free(s[fd]);
// 	s[fd] = NULL;
// 	return (NULL);
// }

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("t.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);

//     return (0);
// }
