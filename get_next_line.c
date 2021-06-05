#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char 		buf[BUFF + 1];
	int			count;
	char 		*ptr;
	int 		i;
	static char	*start_l;
	char		*copy;

	i = 0;
	if (fd < 0 || line == NULL || read(fd, 0, 0))
		return (-1);
	if (start_l)
	{
		*line = ft_strdup(start_l);
		free (start_l);
	}
	else
	{
		*line = ((char *)malloc((BUFF + 1) * sizeof(char)));
	}
	while (!i && (count = read(fd, buf, BUFF)) > 0)
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
	if (count == 0)
		return (0);
	return (1);
}
//
//int main(int argc, char **argv)
//{
//	char	*line;
//	int		fd;
//	int             i;
//	int             j;
//	fd = open("file.txt", O_RDONLY);
//	while ((i = get_next_line(fd, &line)))
//	{
//		printf("%s\n", line);
//	}
//}