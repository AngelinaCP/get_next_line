#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFF 1000

char 	*ft_strjoin(char const *s1, char const *s2);
int get_next_line(int fd, char **line);

#endif
