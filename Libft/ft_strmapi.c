/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:43 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:15:38 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	int		a;

	a = 0;
	if (s != NULL && f != NULL)
	{
		ss = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (ss == NULL)
			return (NULL);
		while (s[a] != '\0')
		{
			ss[a] = f(a, s[a]);
			a++;
		}
		ss[a] = '\0';
		return (ss);
	}
	return (0);
}
