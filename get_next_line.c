#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
	char buf[22 + 1];

	read(fd, buf, 22);
	buf[22] = '\0';
	*line = ft_strdup(buf);
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);

}