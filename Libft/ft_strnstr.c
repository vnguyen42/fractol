/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:40:36 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/16 09:41:00 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (NULL);
	len = ft_strlen(s2);
	if (n < len)
		return (NULL);
	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i <= (n - len))
	{
		if (ft_strncmp(&s1[i], s2, len) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
