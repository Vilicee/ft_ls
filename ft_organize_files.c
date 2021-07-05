/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:17:12 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 16:15:22 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_swap(t_input_data *data)
{
	char	*temp;

	temp = data->fil[data->f];
	data->fil[data->f] = data->fil[data->f + 1];
	data->fil[data->f + 1] = temp;
	if (data->f >= 2)
		data->f = data->f - 2;
	else
		data->f = 0;
}

static void	ft_string_comp(t_input_data *data)
{
	char	*temp;

	if (ft_strcmp(data->fil[data->f], data->fil[data->f + 1]) > 0)
	{
		temp = data->fil[data->f];
		data->fil[data->f] = data->fil[data->f + 1];
		data->fil[data->f + 1] = temp;
		if (data->f >= 2)
			data->f = data->f - 2;
		else
			data->f = 0;
	}
	else
		data->f++;
}

static void	ft_time_order(t_input_data *data, t_args *input)
{
	struct stat	buf;
	struct stat	buf2;

	while (data->f < input->valid_files - 1)
	{
		lstat(data->fil[data->f], &buf);
		lstat(data->fil[data->f + 1], &buf2);
		if (buf.st_mtime < buf2.st_mtime)
			ft_swap(data);
		else if (buf.st_mtime == buf2.st_mtime)
		{
			if (buf.st_mtimespec.tv_nsec < buf2.st_mtimespec.tv_nsec)
				ft_swap(data);
			else if (buf.st_mtimespec.tv_nsec == buf2.st_mtimespec.tv_nsec)
				ft_string_comp(data);
			else
				data->f++;
		}
		else
			data->f++;
	}
}

void	ft_organize_files(t_input_data *data, t_args *input)
{
	char	*temp;

	if (input->t == '1')
		ft_time_order(data, input);
	else
	{
		while (data->f < input->valid_files - 1)
		{
			if (ft_strcmp(data->fil[data->f], data->fil[data->f + 1]) > 0)
			{
				temp = data->fil[data->f + 1];
				data->fil[data->f + 1] = data->fil[data->f];
				data->fil[data->f] = temp;
				data->f = 0;
			}
			else
				data->f++;
		}
	}
}
