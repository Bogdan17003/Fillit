/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:41:54 by bdeomin           #+#    #+#             */
/*   Updated: 2019/02/08 20:41:56 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			part_on_string(char *result, t_figure *figure,
											unsigned short *mask)
{
	unsigned char	b;
	unsigned char	i;

	i = figure->body.index_start;
	b = 0;
	while (i <= figure->body.index_end)
	{
		if (*mask & figure->body.figure.part[b])
			result[i] = figure->character;
		i++;
		b++;
	}
	*mask = *mask << 1;
}

void			print_field(t_param *param, t_figure *figure)
{
	char			result[param->currsize][(param->currsize) + 1];
	unsigned char	a;
	unsigned short	mask;

	ft_memset(result, '.', param->currsize * ((param->currsize) + 1));
	a = 0;
	while (a < (param->currsize))
		result[a++][param->currsize] = '\n';
	while (figure)
	{
		a = 0;
		mask = 1;
		while ((mask < figure->body.byte.position[0]) && ++a)
			mask = mask << 1;
		while (mask <= figure->body.byte.position[1])
			part_on_string(&result[a++][0], figure, &mask);
		figure = figure->next;
	}
	a = 0;
	while (a < (param->currsize))
		write(1, result[a++], param->currsize + 1);
}
