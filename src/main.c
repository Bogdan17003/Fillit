/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:23:19 by eamielin          #+#    #+#             */
/*   Updated: 2019/01/19 20:23:19 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_figure		*figures;
	t_param			*param;
	unsigned char	count_figure;

	if (argc != 2 || ((figures = reading(argv[1], &count_figure)) == NULL))
	{
		write(1, "error\n", 6);
		return (0);
	}
	create_param(&param, count_figure);
	while (!finder(0, figures, param))
	{
		param->currsize++;
		param->size_b = param->size_b << 1;
	}
	print_field(param, figures);
	return (0);
}
