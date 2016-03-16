/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:04:52 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:12:05 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	a;

	a = 0;
	tab = malloc(size);
	if (tab != NULL)
	{
		while (a < size)
		{
			tab[a] = '\0';
			a++;
		}
		return (tab);
	}
	return (NULL);
}
