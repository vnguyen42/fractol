/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:34:16 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:14:25 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	int a;

	a = 0;
	if (s != NULL)
	{
		while (s[a])
		{
			write(fd, &s[a], 1);
			a++;
		}
	}
}
