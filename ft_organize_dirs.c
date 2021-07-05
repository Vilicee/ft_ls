/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_dirs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:49:11 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 16:14:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_swap(t_input_data *data)
{
	char	*temp;

	temp = data->dirs[data->d];
	data->dirs[data->d] = data->dirs[data->d + 1];
	data->dirs[data->d + 1] = temp;
	if (data->d >= 2)
		data->d = data->d - 2;
	else
		data->d = 0;
}

static void	ft_string_comp(t_input_data *data)
{
	char	*temp;

	if (ft_strcmp(data->dirs[data->d], data->dirs[data->d + 1]) > 0)
	{
		temp = data->dirs[data->d];
		data->dirs[data->d] = data->dirs[data->d + 1];
		data->dirs[data->d + 1] = temp;
		if (data->d >= 2)
			data->d = data->d - 2;
		else
			data->d = 0;
	}
	else
		data->d++;
}

static void	ft_time_order(t_input_data *data, t_args *input)
{
	struct stat	buf;
	struct stat	buf2;

	while (data->d < input->valid_directories - 1)
	{
		lstat(data->dirs[data->d], &buf);
		lstat(data->dirs[data->d + 1], &buf2);
		if (buf.st_mtime < buf2.st_mtime)
			ft_swap(data);
		else if (buf.st_mtime == buf2.st_mtime)
		{
			if (buf.st_mtimespec.tv_nsec < buf2.st_mtimespec.tv_nsec)
				ft_swap(data);
			else if (buf.st_mtimespec.tv_nsec == buf2.st_mtimespec.tv_nsec)
				ft_string_comp(data);
			else
				data->d++;
		}
		else
			data->d++;
	}
}

void	ft_organize_dirs(t_input_data *data, t_args *input)
{
	char	*temp;

	if (input->t == '1')
		ft_time_order(data, input);
	else
	{
		while (data->d < input->valid_directories - 1)
		{
			if (ft_strcmp(data->dirs[data->d], data->dirs[data->d + 1]) > 0)
			{
				temp = data->dirs[data->d + 1];
				data->dirs[data->d + 1] = data->dirs[data->d];
				data->dirs[data->d] = temp;
				data->d = 0;
			}
			else
				data->d++;
		}
	}
}
