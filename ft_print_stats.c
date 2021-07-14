/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:24:23 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 14:42:34 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_else(t_no_flags *data, struct stat *stats, int links, int size)
{
	if (data->old == '1')
		ft_printf("%s%*d %-*s  %-*s %*lld %s %2s  %s ", data->rights, links,
			stats->st_nlink, data->name, data->pwd->pw_name, data->gr_int,
			data->group->gr_name, size, stats->st_size, data->month,
			data->date, data->year);
	else
		ft_printf("%s%*d %-*s  %-*s %*lld %s %2s %s ", data->rights, links,
			stats->st_nlink, data->name, data->pwd->pw_name, data->gr_int,
			data->group->gr_name, size, stats->st_size, data->month,
			data->date, data->hour_min);
}

static void	ft_pwd(t_no_flags *data, struct stat *stats, int links, int size)
{
	int	major;
	int	minor;

	if (data->rights[0] == 'c' || data->rights[0] == 'b')
	{
		major = stats->st_rdev >> 24 & 0xff;
		minor = stats->st_rdev & 0xffffff;
		if (data->old == '1')
			ft_printf("%s%*d %-*s  %-*s %4d, %3d %s %2s  %s ", data->rights,
				links, stats->st_nlink, data->name, data->pwd->pw_name,
				data->gr_int, data->group->gr_name, major, minor, data->month,
				data->date, data->year);
		else
			ft_printf("%s%*d %-*s  %-*s %4d, %3d %s %2s %s ", data->rights,
				links, stats->st_nlink, data->name, data->pwd->pw_name,
				data->gr_int, data->group->gr_name, major, minor, data->month,
				data->date, data->hour_min);
	}
	else
		ft_else(data, stats, links, size);
}

static void	ft_no_group(t_no_flags *data, struct stat *stats)
{
	if (data->old == '1')
		ft_printf("%s%*d %-*d  %-*d %*ld %s %2s  %s ", data->rights,
			data->len, stats->st_nlink, data->name, stats->st_uid, data->gr_int,
			stats->st_gid, data->s_l, stats->st_size, data->month,
			data->date, data->year);
	else
		ft_printf("%s%*d %-*d  %-*d %*ld %s %2s %s ", data->rights, data->len,
			stats->st_nlink, data->name, stats->st_uid, data->gr_int,
			stats->st_gid, data->s_l, stats->st_size, data->month,
			data->date, data->hour_min);	
}

void	ft_print_stats(t_no_flags *data, struct stat *stats)
{
	data->len = ft_intlen(data->links) + 1;
	data->s_l = ft_long_long_len(data->size) + 1;
	if (data->pwd && data->group)
		ft_pwd(data, stats, data->len, data->s_l);
	else
	{
		if (data->group)
		{
			if (data->old == '1')
				ft_printf("%s%*d %-*d  %-*s %*ld %s %2s  %s ", data->rights,
					data->len, stats->st_nlink, data->name, stats->st_uid, data->gr_int,
					data->group->gr_name, data->s_l, stats->st_size, data->month,
					data->date, data->year);
			else
				ft_printf("%s%*d %-*d  %-*s %*ld %s %2s %s ", data->rights, data->len,
					stats->st_nlink, data->name, stats->st_uid, data->gr_int,
					data->group->gr_name, data->s_l, stats->st_size, data->month,
					data->date, data->hour_min);
		}
		else
			ft_no_group(data, stats);
	}
	free(data->rights);
}
