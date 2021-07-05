/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_by_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:15:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 16:13:38 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_string_comp(t_no_flags *data, char *temp)
{
	if (ft_strcmp(data->entry[data->i], data->entry[data->i + 1]) > 0)
	{
		temp = data->entry[data->i];
		data->entry[data->i] = data->entry[data->i + 1];
		data->entry[data->i + 1] = temp;
		if (data->i >= 2)
			data->i = data->i - 2;
		else
			data->i = 0;
	}
	else
		data->i++;
}

static void	ft_swap(t_no_flags *data, char *temp)
{
	temp = data->entry[data->i];
	data->entry[data->i] = data->entry[data->i + 1];
	data->entry[data->i + 1] = temp;
	if (data->i >= 2)
		data->i = data->i - 2;
	else
		data->i = 0;
}

static void	ft_part_two(t_no_flags *dt, t_args *arg, struct stat *b, char *t)
{
	if (b->st_mtime < arg->stats.st_mtime)
		ft_swap(dt, t);
	else if (b->st_mtime == arg->stats.st_mtime)
	{
		if (b->st_mtimespec.tv_nsec < arg->stats.st_mtimespec.tv_nsec)
			ft_swap(dt, t);
		else if (b->st_mtimespec.tv_nsec == arg->stats.st_mtimespec.tv_nsec)
			ft_string_comp(dt, t);
		else
			dt->i++;
	}	
	else
		dt->i++;
}

void	ft_order_by_time(t_no_flags *data, t_args *input, char *path)
{
	char		*temp;
	char		*temp2;
	struct stat	buf;

	data->i = 0;
	while (data->i < data->files - 1)
	{
		temp = ft_strcjoin(path, '/', data->entry[data->i]);
		temp2 = ft_strcjoin(path, '/', data->entry[data->i + 1]);
		if (lstat(temp, &buf) == -1 || (lstat(temp2, &input->stats)) == -1)
		{
			free(temp);
			free(temp2);
			return ;
		}
		ft_part_two(data, input, &buf, temp);
		free(temp);
		free(temp2);
	}
}
