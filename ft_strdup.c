/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:15:28 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/23 01:36:04 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
