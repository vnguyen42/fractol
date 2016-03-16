/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:36:27 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:29:37 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	while (*alst != NULL)
	{
		list = (*alst)->next;
		del((*alst), (*alst)->content_size);
		free(list);
		*alst = list;
	}
	*alst = NULL;
}
