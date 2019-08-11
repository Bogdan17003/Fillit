/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:19:36 by bdeomin           #+#    #+#             */
/*   Updated: 2019/02/08 20:19:47 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	to_byte(char ch, unsigned short *figure, unsigned short *mask)
{
	if (ch == '#')
		*figure = *figure | *mask;
	else if (ch != '.')
		return (0);
	*mask = *mask >> 1;
	return (1);
}

unsigned char	is_n(char ch)
{
	return (ch == '\n') ? 1 : 0;
}

t_figure		*find(char *buf, int count)
{
	unsigned short	figures[count];
	int				i;
	int				cur;
	unsigned short	mask;

	ft_bzero(&figures, count * sizeof(short));
	cur = -1;
	while (++cur < count)
	{
		i = 0;
		mask = 32768;
		while (i < 20)
		{
			while ((i + 1) % 5)
				if (!to_byte(buf[i++], &figures[cur], &mask))
					return (NULL);
			if (!is_n(buf[i++]))
				return (NULL);
		}
		if (((cur + 1) != count) && (buf[i] == '\n'))
			buf += 21;
		else
			return ((cur + 1) == count) ? mover(figures, count) : NULL;
	}
	return (NULL);
}

t_figure		*reading(char *file, unsigned char *count_figure)
{
	int			fd;
	int			rbyte;
	char		*buf;
	t_figure	*result;

	result = NULL;
	if ((fd = open(file, O_RDONLY)) > 0)
	{
		if ((buf = (char *)malloc(BUF_SIZE)))
		{
			if ((((rbyte = read(fd, buf, BUF_SIZE)) + 1) % 21) == 0)
			{
				*count_figure = (rbyte + 1) / 21;
				result = find(buf, *count_figure);
			}
			free(buf);
		}
		close(fd);
	}
	if (result)
		return (result);
	return (NULL);
}
