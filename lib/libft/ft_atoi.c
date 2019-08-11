/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:40:17 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/07 21:40:18 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				znak;
	unsigned int	result;
	unsigned int	max;

	i = 0;
	znak = 1;
	result = 0;
	max = 2147483647;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i++] == '-')
		znak = -1;
	else if (str[i - 1] != '+')
		i--;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * znak);
}
