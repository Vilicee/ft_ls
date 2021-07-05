/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:37:55 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 12:59:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_modify_file(char *path, t_input_data *data)
{
	struct stat	buf;
	char		*ptr;
	char		*temp;

	lstat(path, &buf);
	ptr = (char *)malloc(sizeof(char) * (buf.st_size + 1));
	if (!ptr)
	{
		ft_printf("MALLOC ERROR\n");
		return ;
	}
	readlink(path, ptr, buf.st_size + 1);
	ptr[buf.st_size] = '\0';
	temp = ft_strjoin(path, " -> ");
	free(data->fil[data->f]);
	data->fil[data->f] = ft_strjoin(temp, ptr);
	free(temp);
	free(ptr);
}
