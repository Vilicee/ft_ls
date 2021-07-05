/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:46:09 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 15:48:46 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_part_one(t_no_flags *data, struct stat *stats)
{
	if (stats->st_mode && S_ISDIR(stats->st_mode))
		data->rights[0] = 'd';
	if (stats->st_mode && S_ISLNK(stats->st_mode))
		data->rights[0] = 'l';
	if (stats->st_mode && S_ISSOCK(stats->st_mode))
		data->rights[0] = 's';
	if (stats->st_mode && S_ISCHR(stats->st_mode))
		data->rights[0] = 'c';
	if (stats->st_mode && S_ISBLK(stats->st_mode))
		data->rights[0] = 'b';
	if (stats->st_mode & S_IRUSR)
		data->rights[1] = 'r';
	if (stats->st_mode & S_IWUSR)
		data->rights[2] = 'w';
	if (stats->st_mode & S_ISUID)
	{
		if (stats->st_mode & S_IXUSR)
			data->rights[3] = 's';
		else
			data->rights[3] = 'S';
	}
	else if (stats->st_mode & S_IXUSR)
		data->rights[3] = 'x';
}

static void	ft_part_two(t_no_flags *data, struct stat *stats)
{
	if (stats->st_mode & S_IRGRP)
		data->rights[4] = 'r';
	if (stats->st_mode & S_IWGRP)
		data->rights[5] = 'w';
	if (stats->st_mode & S_ISGID)
	{
		data->rights[6] = 'S';
		if (stats->st_mode & S_IXGRP)
			data->rights[6] = 's';
	}
	else if (stats->st_mode & S_IXGRP)
		data->rights[6] = 'x';
	if (stats->st_mode & S_IROTH)
		data->rights[7] = 'r';
	if (stats->st_mode & S_IWOTH)
		data->rights[8] = 'w';
	if (stats->st_mode & S_ISVTX)
	{
		data->rights[9] = 'T';
		if (stats->st_mode & S_IXOTH)
			data->rights[9] = 't';
	}
	else if (stats->st_mode & S_IXOTH)
		data->rights[9] = 'x';
}

void	ft_set_rights(t_no_flags *data, struct stat *stats)
{
	data->rights = (char *)malloc(sizeof(char) * 12);
	data->rights = ft_memset(data->rights, '-', 10);
	ft_part_one(data, stats);
	ft_part_two(data, stats);
	if (data->extend == '1')
		data->rights[10] = '@';
	else
		data->rights[10] = ' ';
	data->rights[11] = '\0';
}
