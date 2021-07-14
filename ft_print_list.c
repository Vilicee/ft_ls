/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:42:49 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 14:12:58 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_check_stat(char *t, t_args *in, struct stat *st, char *path)
{
	if (in->R == '1')
	{
		if (lstat(t, st) == -1)
		{
			free(t);
			return (-1);
		}
	}
	else
	{
		if (lstat(path, st) == -1)
		{
			free(t);
			return (-1);
		}
	}
	return (0);
}

static void	ft_print_normal(t_no_flags *data, t_args *input, char *path)
{
	char	*temp;

	data->i = 0;
	while (data->i < data->files)
	{
		if (input->l == '1')
		{
			temp = ft_strcjoin(path, '/', data->entry[data->i]);
			if (input->R == '1' || input->dir_input == '1')
			{
				ft_file_stat(temp, data);
				if (data->l == '1')
					ft_modify_name(temp, data);
			}
			else
			{
				ft_file_stat(data->entry[data->i], data);
				if (data->l == '1')
					ft_modify_name(data->entry[data->i], data);
			}
			free(temp);
		}
		ft_printf("%s\n", data->entry[data->i]);
		data->i++;
	}
}

static void	ft_print_reverse(t_no_flags *data, t_args *input, char *path)
{
	char	*temp;

	data->i = data->files - 1;
	while (data->i >= 0)
	{
		if (input->l == '1')
		{
			temp = ft_strcjoin(path, '/', data->entry[data->i]);
			if (input->R == '1' || input->dir_input == '1')
			{
				ft_file_stat(temp, data);
				if (data->l == '1')
					ft_modify_name(temp, data);
			}
			else
			{
				ft_file_stat(data->entry[data->i], data);
				if (data->l == '1')
					ft_modify_name(data->entry[data->i], data);
			}
			free(temp);
		}
		ft_printf("%s\n", data->entry[data->i]);
		data->i--;
	}
}

void	ft_print_list(t_no_flags *data, t_args *input, char *path)
{
	struct stat	stats;
	char		*temp;

	temp = ft_strcjoin(path, '/', data->entry[0]);
	if (ft_check_stat(temp, input, &stats, path) == -1)
		return ;
	free(temp);
	if (input->l == '1' && data->files > 0)
		ft_printf("total %d\n", data->total);
	if (input->r == '1')
		ft_print_reverse(data, input, path);
	else
		ft_print_normal(data, input, path);
}
