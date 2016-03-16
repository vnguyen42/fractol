/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:48:33 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:15:53 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	a;

	a = 0;
	tab = malloc(sizeof(char) * size + 1);
	if (tab != NULL)
	{
		while (a < size)
		{
			tab[a] = '\0';
			a++;
		}
		tab[a] = '\0';
		return (tab);
	}
	else
		return (NULL);
}
