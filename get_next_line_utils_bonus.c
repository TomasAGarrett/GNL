/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:42:58 by jalmeida          #+#    #+#             */
/*   Updated: 2022/09/11 05:26:49 by jalmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int contem_novalinha(const char *y)
{
	int i;

	i = 0;
	while (y[i])
	{
		if (y[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (total != 0)
	{
		*p = '\0';
		p++;
		total--;
	}
	return (r);
}

char	*junta_misto(const char *y1, const char *y2)
{
	char	*y;
	int		len;
	int		i;

	len = 0;
	if (!y1 && !y2)
		return (NULL);
	while (y1 && y1[len])
		len++;
	i = 0;
	while (y2 && y2[i])
		i++;
	y = ft_malloc_zero(len + i + 1, sizeof * y);
	if (!y)
		return (NULL);
	len = -1;
	while (y1 && y1[++len])
		y[len] = y1[len];
	i = -1;
	while (y2 && y2[++i])
		y[len + i] = y2[i];
	return (y);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_malloc_zero(i + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

void	ft_liberta_misto(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}