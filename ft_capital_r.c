/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capital_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:01:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 17:29:39 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_print_directory(t_no_flags *data, t_args *input, char *path)
{
	data->old = '0';
	if (input->t == '1')
		ft_order_by_time(data, input, path);
	else
		ft_ascii_order(data);
	ft_print_list(data, input, path);
}

static void	ft_rev(t_args *input, t_no_flags *data, char *temp)
{
	struct stat	stats;
	int			i;
	char		*f_temp;

	i = data->files - 1;
	while (i >= 0)
	{
		f_temp = ft_strcjoin(temp, '/', data->entry[i]);
		lstat(f_temp, &stats);
		if (stats.st_mode && S_ISDIR(stats.st_mode))
		{
			if (ft_dots(data->entry[i]) == 0)
				ft_capital_r(input, temp, data->entry[i--]);
			else
				i--;
		}
		else if (!S_ISDIR(stats.st_mode))
			i--;
		free(f_temp);
	}	
}

static void	ft_normal(t_args *input, t_no_flags *data, char *temp)
{
	struct stat	stats;
	char		*f_temp;
	int			i;

	i = 0;
	while (i < data->files)
	{
		f_temp = ft_strcjoin(temp, '/', data->entry[i]);
		lstat(f_temp, &stats);
		if (stats.st_mode && S_ISDIR(stats.st_mode))
		{
			if (ft_dots(data->entry[i]) == 0)
				ft_capital_r(input, temp, data->entry[i++]);
			else
				i++;
		}
		else if (!S_ISDIR(stats.st_mode))
			i++;
		if (f_temp)
			free(f_temp);
	}
}

static void	ft_print_out(t_args *inp, t_no_flags *dt, char *temp, char *path)
{
	if (inp->r == '1')
		ft_rev(inp, dt, temp);
	else
		ft_normal(inp, dt, temp);
	if (path)
		free(temp);
	ft_free(dt);
}

int	ft_capital_r(t_args *input, char *former, char *latter)
{	
	t_no_flags	data;
	char		*temp;

	if (!latter)
		temp = former;
	else
	{
		if (former[0] == '/' && ft_strlen(former) == 1)
			temp = ft_strjoin(former, latter);
		else
			temp = ft_strcjoin(former, '/', latter);
	}
	if (ft_save_entries(&data, input, temp) == -1)
		return (ft_parse_rec_output(input, latter, former, temp));
	if (latter)
		ft_printf("\n%s:\n", temp);
	ft_print_directory(&data, input, temp);
	ft_print_out(input, &data, temp, latter);
	return (0);
}
