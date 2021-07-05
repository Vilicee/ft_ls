/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:02:53 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 14:26:10 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	result(char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	if (*str != NULL)
	{
		while ((*str)[len] != '\n' && (*str)[len] != '\0')
			len++;
		if ((*str)[len] == '\n')
		{
			*line = ft_strsub(*str, 0, len);
			temp = ft_strdup(&(*str)[len + 1]);
			free(*str);
			*str = temp;
			if ((*str)[0] == '\0')
				ft_strdel(str);
		}
		else
		{
			*line = ft_strdup(*str);
			ft_strdel(str);
		}
		return (1);
	}
	return (0);
}

int	ft_gnl(const int fd, char **line)
{
	static char	*str[4096];
	t_gnl		data;

	if (!line || !fd)
		return (-1);
	data.ret = read(fd, data.buf, GNL_BUFF_SIZE);
	if (data.ret == -1)
		return (-1);
	while (data.ret)
	{
		data.buf[data.ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(data.buf);
		else
		{
			data.temp = ft_strjoin(str[fd], data.buf);
			free(str[fd]);
			str[fd] = data.temp;
		}
		if (ft_strchr(data.buf, '\n'))
			break ;
		data.ret = read(fd, data.buf, GNL_BUFF_SIZE);
	}
	return (result(&str[fd], line));
}
