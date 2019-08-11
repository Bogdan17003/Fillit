/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 23:10:46 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/19 23:10:48 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(char *texterr, char *textdiag, int numerr, int mode)
{
	if (mode == -1)
		return (numerr);
	if (mode != 1 && texterr)
	{
		write(2, texterr, ft_strlen(texterr));
		write(2, "\n", 1);
	}
	if (mode != 0 && textdiag)
	{
		write(2, textdiag, ft_strlen(textdiag));
		write(2, "\n", 1);
	}
	return (numerr);
}
