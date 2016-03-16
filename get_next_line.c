/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:51:51 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 15:14:48 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char *buf, size_t size)
{
	char *new_memmory;

	new_memmory = ft_strnew(size);
	if (buf != NULL)
		if (new_memmory != NULL)
			ft_memcpy(new_memmory, buf, ft_strlen(buf));
	ft_memdel((void **)&buf);
	return (new_memmory);
}

static int	ft_destruction(char *buf)
{
	int index;

	index = 0;
	if (buf == NULL)
		return (0);
	while (buf[index] != '\n' && buf[index] != '\0')
		index++;
	if (buf[index] == '\0')
		return (0);
	if (buf[index] == '\n')
	{
		buf[index] = '\0';
		if (buf[index + 1] == '\0')
			return (0);
	}
	return (1);
}

static char	*ft_strdup_2_0(char *buf, char *tmp)
{
	int		a;
	int		b;
	char	*stick;

	a = 0;
	b = 0;
	if (tmp == NULL)
		return (buf);
	stick = ft_strnew(ft_strlen(tmp) + ft_strlen(buf));
	while (tmp[b] != '\0')
	{
		stick[a] = tmp[b];
		a++;
		b++;
	}
	b = 0;
	while (buf[b] != '\0')
	{
		stick[a] = buf[b];
		b++;
		a++;
	}
	ft_memdel((void **)&buf);
	return (stick);
}

int			get_get(int fd, char **buf)
{
	char	*tmp;
	int		conteur;
	int		file;

	conteur = 0;
	tmp = *buf;
	*buf = ft_strnew(BUFF_SIZE);
	while ((file = read(fd, *buf + BUFF_SIZE * conteur, BUFF_SIZE)) > 0)
	{
		if (file == BUFF_SIZE)
			*buf = ft_realloc(*buf, BUFF_SIZE * (conteur + 2));
		if (ft_strchr(*buf, '\n'))
		{
			*buf = ft_strdup_2_0(*buf, tmp);
			return (1);
		}
		conteur++;
	}
	if (file == -1)
		return (-1);
	*buf = ft_strdup_2_0(*buf, tmp);
	if (file == 0 && ft_strlen(*buf) == 0)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *buf = NULL;
	static char *sup = NULL;
	int			chekout;
	int			a;

	chekout = 1;
	if (buf == NULL || ft_strchr(buf, '\n') == NULL)
	{
		chekout = get_get(fd, &buf);
		sup = buf;
	}
	if (chekout == -1)
		return (-1);
	if (chekout == 0)
		buf = NULL;
	a = ft_destruction(buf);
	*line = ft_strdup(buf);
	if (a == 1)
		buf = ft_strlen(buf) + buf + 1;
	else
	{
		free(sup);
		buf = NULL;
	}
	return (chekout);
}
