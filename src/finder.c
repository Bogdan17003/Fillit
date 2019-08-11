/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:38:12 by bdeomin           #+#    #+#             */
/*   Updated: 2019/02/08 20:38:15 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			new_place(t_body *figure_body, t_param *param)
{
	if (figure_body->index_end + 1 < param->currsize)
	{
		figure_body->index_start++;
		figure_body->index_end++;
	}
	else if (figure_body->byte.position[1] << 1 <= param->size_b)
	{
		figure_body->figure.parts = figure_body->figure.parts << 1;
		figure_body->byte.positions = figure_body->byte.positions << 1;
		figure_body->index_end -= figure_body->index_start;
		figure_body->index_start = 0;
	}
	else
		return (0);
	return (1);
}

char			good_place(t_body *figure_body, t_param *param)
{
	if (!(figure_body->index_end < param->currsize))
		return (0);
	if (!(figure_body->byte.position[1] <= param->size_b))
		return (0);
	return (1);
}

char			checker(t_body *figure_body, short *new_field, t_param *param,
																	char move)
{
	unsigned long	*temp;

	while (1)
	{
		if (!move)
		{
			if (!good_place(figure_body, param))
				return (0);
		}
		else
		{
			if (!new_place(figure_body, param))
				return (0);
		}
		temp = (unsigned long *)&new_field[figure_body->index_start];
		if (figure_body->figure.parts & *temp)
			move = 1;
		else
		{
			*temp = figure_body->figure.parts | *temp;
			return (1);
		}
	}
}

char			finder(const short *field, t_figure *figure, t_param *param)
{
	t_body	figure_body;
	short	new_field[param->currsize + 3];
	char	move;

	if (figure == NULL)
		return (1);
	ft_memcpy(&figure_body, &figure->body, sizeof(t_body));
	if (field)
		ft_memcpy(&new_field, field, sizeof(short) * (param->currsize + 3));
	else
		ft_bzero(&new_field, sizeof(short) * param->currsize + 3);
	move = 0;
	while (checker(&figure_body, new_field, param, move))
	{
		if (finder(new_field, figure->next, param))
		{
			ft_memcpy(&figure->body, &figure_body, sizeof(t_body));
			return (1);
		}
		field ? ft_memcpy(&new_field, field, sizeof(short) *
			(param->currsize + 3)) : ft_bzero(&new_field, sizeof(short)
			* param->currsize + 3);
		move = 1;
	}
	return (0);
}
