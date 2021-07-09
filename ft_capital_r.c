/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capital_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:01:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/08 14:42:06 by wvaara           ###   ########.fr       */
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

int	ft_capital_r(t_args *input, char *former, char *latter)
{	
	t_no_flags	data;
	char		*temp;

	if (!latter)
		temp = former;
	else
		temp = ft_strcjoin(former, '/', latter);
	if (ft_save_entries(&data, input, temp) == -1)
	{
		if (input->argc == 0)
			ft_printf("ft_ls: %s: Permission denied\n", latter);
		if (latter)
			free(temp);
		return (-1);
	}
	if (latter)
		ft_printf("\n%s:\n", temp);
	ft_print_directory(&data, input, temp);
	if (input->r == '1')
		ft_rev(input, &data, temp);
	else
		ft_normal(input, &data, temp);
	if (latter)
		free(temp);
	ft_free(&data);
	return (0);
}
