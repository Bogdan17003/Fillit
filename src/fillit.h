/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:52:55 by eamielin          #+#    #+#             */
/*   Updated: 2019/01/20 18:52:56 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "libft.h"
# define BUF_SIZE 547
# include <fcntl.h>

typedef struct			s_param
{
	unsigned short		size_b;
	unsigned char		currsize;
}						t_param;

typedef struct			s_body
{
	union
	{
		unsigned long	parts;
		unsigned short	part[4];
	}					figure;
	union
	{
		unsigned int	positions;
		unsigned short	position[2];
	}					byte;
	unsigned char		index_start;
	unsigned char		index_end;
}						t_body;

typedef struct			s_figure
{
	struct s_figure		*next;
	t_body				body;
	char				character;
}						t_figure;

t_figure				*reading(char *file, unsigned char *count_figure);
t_figure				*mover(unsigned short *figures, int fig);
char					finder(const short *field, t_figure *figure,
															t_param *param);
void					create_param(t_param **param,
												unsigned char count_figure);
void					print_field(t_param *param, t_figure *figure);

#endif
