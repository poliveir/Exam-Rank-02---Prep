#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int	i;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)&(*s));
		s++;
	}
	if (*s == (char)c)
		return ((char *)&(*s));
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	int	len;
	int	i;
	
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char*)malloc(len + 1);
	i = 0;
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

int	get_next_line(char **line)
{
	int	ret;
	char	buf[2];
	char	*temp;

	if (!line || read(0, buf , 0) < 0)
		return (-1);
	*line = ft_strdup("");
	while ((ret = read(0, buf, 1)) > 0 && buf[0] != '\n')
	{
		buf[ret] = '\0';
		temp = ft_strjoin(*line, buf);
		free(*line);
		*line = temp;
	}
		return (ret);
}
