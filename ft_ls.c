/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:46:20 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/09 14:05:23 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_just_options(t_args *input)
{
	t_no_flags	init_data;

	if (input->R == '1')
	{
		ft_capital_r(input, ".", NULL);
		return (0);
	}
	else
		ft_print_entries(input, &init_data);
	return (0);
}

static void	ft_handle_errors(t_input_data *data, t_args *input)
{
	data->e = 0;
	while (data->e < input->errors)
		ft_printf("ft_ls: %s: No such file or directory\n",
			data->err[data->e++]);
}

static void	ft_free_input(t_input_data *data, t_args *input)
{
	if (input->valid_directories > 0)
	{
		while (data->d < input->valid_directories)
			free(data->dirs[data->d++]);
		free(data->dirs);
	}
	if (input->valid_files > 0)
	{
		while (data->f < input->valid_files)
			free(data->fil[data->f++]);
		free(data->fil);
	}
	if (input->errors > 0)
	{
		while (data->e < input->errors)
			free(data->err[data->e++]);
		free(data->err);
	}
}

int	ft_ls(t_input_data *data, t_args *input)
{
	if (input->errors == 0 && input->valid_directories == 0
		&& input->valid_files == 0)
		ft_just_options(input);
	else
	{
		input->dir_input = '1';
		if (input->errors > 0)
			ft_handle_errors(data, input);
		if (input->valid_files > 0)
			ft_handle_valid_files(data, input);
		if (input->valid_directories > 0)
			ft_handle_directories(data, input);
		data->d = 0;
		data->f = 0;
		data->e = 0;
		ft_free_input(data, input);
	}
	return (0);
}
