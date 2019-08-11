/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:45:04 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/14 19:45:05 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	del((*alst)->content, (*alst)->content_size);
	next = (*alst)->next;
	free(*alst);
	*alst = next;
}
