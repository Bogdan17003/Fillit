/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createparam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:40:49 by bdeomin           #+#    #+#             */
/*   Updated: 2019/02/08 20:40:51 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	start_size(unsigned char count_figure)
{
	if (count_figure <= 2)
		return (3);
	if (count_figure <= 4)
		return (4);
	if (count_figure <= 6)
		return (5);
	if (count_figure <= 9)
		return (6);
	if (count_figure <= 12)
		return (7);
	if (count_figure <= 16)
		return (8);
	if (count_figure <= 20)
		return (9);
	if (count_figure <= 25)
		return (10);
	return (11);
}

void			create_param(t_param **param, unsigned char count_figure)
{
	*param = (t_param *)malloc(sizeof(t_param));
	(*param)->currsize = start_size(count_figure);
	(*param)->size_b = 1 << ((*param)->currsize - 1);
}
