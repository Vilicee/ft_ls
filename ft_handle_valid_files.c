/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_valid_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:39:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 16:03:48 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_reverse(t_input_data *data, t_args *input)
{
	t_no_flags	ls_data;

	data->f = input->valid_files - 1;
	ls_data.name = 0;
	while (data->f >= 0)
	{
		if (input->l == '1')
			ft_file_stat(data->fil[data->f], &ls_data);
		ft_printf("%s", data->fil[data->f]);
		if (input->l == '1' && data->f != 0)
			write(1, "\n", 1);
		data->f--;
	}
}

static void	ft_normal(t_input_data *data, t_args *input)
{
	t_no_flags	ls_data;

	data->f = 0;
	ls_data.name = 0;
	ls_data.links = 0;
	ls_data.size = 0;
	ls_data.gr_int = 0;
	while (data->f < input->valid_files)
	{
		if (input->l == '1')
			ft_file_stat(data->fil[data->f], &ls_data);
		if (ls_data.l == '1')
			ft_modify_file(data->fil[data->f], data);
		ft_printf("%s", data->fil[data->f]);
		if (input->l == '1' && data->f < input->valid_files - 1)
			write(1, "\n", 1);
		data->f++;
	}
}

void	ft_handle_valid_files(t_input_data *data, t_args *input)
{	
	if (input->r == '1')
		ft_reverse(data, input);
	else
		ft_normal(data, input);
	write(1, "\n", 1);
	if (input->valid_directories > 0)
		write(1, "\n", 1);
}
