/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:38:00 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/16 10:06:15 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *res;
	t_list *appli;

	res = NULL;
	if (lst != NULL && f != NULL)
	{
		res = (*f)(lst);
		if (res == NULL)
			return (NULL);
		list = res;
		lst = lst->next;
		while (lst != NULL)
		{
			appli = (*f)(lst);
			if (appli == NULL)
				return (res);
			list->next = appli;
			list = appli;
			lst = list->next;
		}
	}
	return (res);
}
