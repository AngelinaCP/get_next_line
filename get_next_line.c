#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char 	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(s1);
	d = (char *)malloc(sizeof(char) * (length + 1));
	if (d == 0)
		return (NULL);
	while (i < length)
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = 0;
	return (d);
}

int get_next_line(int fd, char **line)
{
	char 	buf[BUFF + 1];
	int			count;
	char 		*ptr;
	int 		i;
	static char	*start_l;

	i = 0;
	printf("\n|%s|", start_l);
	if (start_l)
		*line = ft_strdup(start_l);
	else
		if (!(*line = ((char *)malloc(1000 * sizeof(char)))))
			return (-1);
	while (!i && (count = read(fd, buf, 15)))
	{
		buf[count] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			i = 1;
		}
		*line = ft_strjoin(*line, buf);
	}
	start_l = ft_strdup(++ptr);
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);

	get_next_line(fd, &line);
	printf("\n\n%s", line);




}