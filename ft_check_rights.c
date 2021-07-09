/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:55:27 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/08 16:22:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_check_rights(t_input_data *data)
{
	struct stat	buf;

	if (lstat(data->dirs[data->d], &buf) == -1)
		return (-1);
	if (buf.st_mode & S_IXUSR)
		return (0);
	else
		return (-1);
	return (0);
}
