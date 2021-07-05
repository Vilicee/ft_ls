/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:28 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 16:15:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_swap(t_input_data *data)
{
	char	*temp;

	temp = data->err[data->e];
	data->err[data->e] = data->err[data->e + 1];
	data->err[data->e + 1] = temp;
	if (data->e >= 2)
		data->e = data->e - 2;
	else
		data->e = 0;
}

static void	ft_string_comp(t_input_data *data)
{
	char	*temp;

	if (ft_strcmp(data->err[data->e], data->err[data->e + 1]) > 0)
	{
		temp = data->err[data->e];
		data->err[data->e] = data->err[data->e + 1];
		data->err[data->e + 1] = temp;
		if (data->e >= 2)
			data->e = data->e - 2;
		else
			data->e = 0;
	}
	else
		data->e++;
}

static void	ft_time_order(t_input_data *data, t_args *input)
{
	struct stat	buf;
	struct stat	buf2;

	while (data->e < input->errors - 1)
	{
		lstat(data->err[data->e], &buf);
		lstat(data->err[data->e + 1], &buf2);
		if (buf.st_mtime < buf2.st_mtime)
			ft_swap(data);
		else if (buf.st_mtime == buf2.st_mtime)
		{
			if (buf.st_mtimespec.tv_nsec < buf2.st_mtimespec.tv_nsec)
				ft_swap(data);
			else if (buf.st_mtimespec.tv_nsec == buf2.st_mtimespec.tv_nsec)
				ft_string_comp(data);
			else
				data->e++;
		}
		else
			data->e++;
	}
}

void	ft_organize_errors(t_input_data *data, t_args *input)
{
	char	*temp;

	if (input->t == '1')
		ft_time_order(data, input);
	else
	{
		while (data->e < input->errors - 1)
		{
			if (ft_strcmp(data->err[data->e], data->err[data->e + 1]) > 0)
			{
				temp = data->err[data->e + 1];
				data->err[data->e + 1] = data->err[data->e];
				data->err[data->e] = temp;
				data->e = 0;
			}
			else
				data->e++;
		}
	}
}
