/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:01:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 14:13:14 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_save_file_stats(t_no_flags *data, struct stat *stats)
{
	ft_set_rights(data, stats);
	if (data->rights[0] == 'l')
		data->l = '1';
	data->pwd = getpwuid(stats->st_uid);
	data->group = getgrgid(stats->st_gid);
	ft_mod_time(data, stats);
}

int	ft_file_stat(char *file, t_no_flags *data)
{
	struct stat	stats;

	data->l = '0';
	data->extend = '0';
	if (listxattr(file, NULL, 10000, XATTR_NOFOLLOW) > 0)
		data->extend = '1';
	if (lstat(file, &stats) == -1)
		return (-1);
	ft_save_file_stats(data, &stats);
	ft_print_stats(data, &stats);
	return (0);
}
