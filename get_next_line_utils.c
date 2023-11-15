#include "get_next_line.h"

char	*ft_strcat_and_copy(char *dest, const char *src, int is_copy)
{
	char	*dest_end;

	dest_end = dest;
	if (is_copy)
		while (*src)
			*dest_end++ = *src++;
	else
	{
		while (*dest_end)
			dest_end++;
		while (*src)
			*dest_end++ = *src++;
	}
	*dest_end = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	if (*s == 0 || start >= ft_strlen(s) || len == 0)
		substr[i] = 0;
	while (s[start] != 0 && len > 0 && ft_strlen(s) > 0)
	{
		substr[i++] = s[start++];
		len--;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen(s1) + 1);
	if (s2)
		ft_strcat_and_copy(s2, s1, 1);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 ||!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_strcat_and_copy(str, s1, 1);
	ft_strcat_and_copy(str, s2, 0);
	return (str);
}
