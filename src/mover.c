/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:26:04 by bdeomin           #+#    #+#             */
/*   Updated: 2019/02/08 20:26:07 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure		*create_figure(t_figure **prev, char ch, unsigned long temp)
{
	t_figure		*new;
	unsigned char	i;
	unsigned short	mask;

	new = (t_figure *)malloc(sizeof(t_figure));
	ft_bzero(new, sizeof(t_figure));
	new->character = ch;
	new->body.figure.parts = temp;
	new->body.byte.position[0] = 1;
	mask = 1;
	while ((mask & new->body.figure.part[0]) ||
		(mask & new->body.figure.part[1]) || (mask & new->body.figure.part[2])
		|| (mask & new->body.figure.part[3]))
		mask = mask << 1;
	new->body.byte.position[1] = mask >> 1;
	new->body.index_start = 0;
	i = 3;
	while (new->body.figure.part[i] == 0)
		i--;
	new->body.index_end = i;
	new->next = *prev;
	return ((*prev = new));
}

void			move_mask_bytes(unsigned short *mask, unsigned long *byte)
{
	*mask = *mask >> 4;
	*byte = *byte << 1;
}

t_figure		*convert(unsigned short *figures, int count, int i)
{
	unsigned long	temp;
	unsigned short	mask;
	unsigned long	byte;
	t_figure		*result;

	result = NULL;
	while ((--count) >= 0)
	{
		byte = 1;
		temp = 0;
		i = 0;
		while (i < 4)
		{
			mask = 32768 >> i++;
			while (mask)
			{
				if (figures[count] & mask)
					temp = temp | byte;
				move_mask_bytes(&mask, &byte);
			}
			byte = byte << 12;
		}
		create_figure(&result, 'A' + count, temp);
	}
	return (result);
}

t_figure		*check_valide_figure(unsigned short *figures, int fig)
{
	int						i;
	int						j;
	const unsigned short	valide_figures[19] = {	51328, 50240, 57856, 59392,
		11776, 36352, 35008, 17600,
		35968, 19520, 58368, 19968,
		52224,
		50688, 19584, 35904, 27648,
		61440, 34952};

	i = -1;
	j = -1;
	while (++i < fig)
	{
		while (++j < 19)
		{
			if (figures[i] == valide_figures[j])
			{
				j = -1;
				break ;
			}
		}
		if (j != -1)
			return (NULL);
	}
	return (convert(figures, fig, 0));
}

t_figure		*mover(unsigned short *figures, int fig)
{
	int i;

	i = -1;
	while (++i < fig)
	{
		if (figures[i] == 0)
			return (NULL);
		while ((figures[i] & 61440) == 0)
			figures[i] <<= 4;
		while ((figures[i] & 34952) == 0)
			figures[i] <<= 1;
	}
	return (check_valide_figure(figures, fig));
}
