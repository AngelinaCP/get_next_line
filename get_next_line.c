#include "get_next_line.h"

char *next_line(char *start_l, char **line)
{
	char		*ptr2;

	ptr2 = NULL;
	if (start_l)
	{
		if ((ptr2 = ft_strchr(start_l, '\n')))
		{
			*ptr2 = '\0';
			*line = ft_strdup(start_l);
			ptr2++;
			ft_strcpy(start_l, ptr2);
		}
		else
		{
			*line = ft_strdup(start_l);
			free(start_l);
			start_l = NULL;
		}
	}
	else
	{
		*line = ((char *)malloc((BUFFER + 1) * sizeof(char)));
	}
	return (ptr2);
}

int get_next_line(int fd, char **line)
{
	char 		buf[BUFFER + 1];
	int			count;
	char 		*ptr;
	int 		i;
	static char	*start_l;
	char		*copy;
	char 		*p;

	i = 0;
	if (fd < 0 || line == NULL || read(fd, 0, 0))
		return (-1);
	p = next_line(start_l, line);
	while (!p && (count = read(fd, buf, BUFFER)) > 0)
	{
		buf[count] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			i = 1;
			start_l = ft_strdup(++ptr);
		}
		copy = *line;
		*line = ft_strjoin(*line, buf);
		free (copy);
	}
	printf("|%s|", start_l);
	if (start_l)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int i;
	fd = open("file.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free (line);
	}
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
}