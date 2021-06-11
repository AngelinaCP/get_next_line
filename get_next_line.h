#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//#define BUFFER_SIZE 1

char 	*ft_strjoin(char const *s1, char const *s2);
int 	get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char *ft_strcpy(char *dest, char *src);

#endif
