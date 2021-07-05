/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:29:27 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 14:36:48 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_check(char *path, t_no_flags *data)
{
	if (ft_strcmp(path, "/dev/stderr") == 0)
	{
		free(data->entry[data->i]);
		data->entry[data->i] = ft_strdup("stderr -> fd/2");
		return (-1);
	}
	if (ft_strcmp(path, "/dev/stdin") == 0)
	{
		free(data->entry[data->i]);
		data->entry[data->i] = ft_strdup("stdin -> fd/0");
		return (-1);
	}
	if (ft_strcmp(path, "/dev/stdout") == 0)
	{
		free(data->entry[data->i]);
		data->entry[data->i] = ft_strdup("stdout -> fd/1");
		return (-1);
	}
	return (0);
}

void	ft_modify_name(char *path, t_no_flags *data)
{
	struct stat	buf;
	char		*ptr;
	char		*temp;

	if (ft_check(path, data) == -1)
		return ;
	lstat(path, &buf);
	ptr = (char *)malloc(sizeof(char) * (buf.st_size + 1));
	if (!ptr)
	{
		ft_printf("MALLOC ERROR\n");
		return ;
	}
	readlink(path, ptr, buf.st_size + 1);
	ptr[buf.st_size] = '\0';
	temp = ft_strjoin(data->entry[data->i], " -> ");
	free(data->entry[data->i]);
	data->entry[data->i] = ft_strjoin(temp, ptr);
	free(temp);
	free(ptr);
}
