/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_directories.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:45:25 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/08 16:29:00 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_check_for_read(t_input_data *data, t_args *input)
{
	DIR	*dir;

	dir = opendir(data->dirs[data->d]);
	if (!dir)
	{
		if (input->argc > 1)
			ft_printf("%s:\n", data->dirs[data->d]);
		ft_printf("ft_ls: %s: Permission denied\n", data->dirs[data->d]);
		return (-1);
	}
	return (0);
}

static void	ft_execute(t_input_data *data, t_no_flags *entries, t_args *input)
{
	if (input->argc > 1)
		ft_printf("%s:\n", data->dirs[data->d]);
	if (ft_save_entries(entries, input, data->dirs[data->d]) == 0)
	{
		if (input->t == '1')
			ft_order_by_time(entries, input, data->dirs[data->d]);
		else
			ft_ascii_order(entries);
		ft_print_list(entries, input, data->dirs[data->d]);
		ft_free(entries);
	}
}

static void	ft_reverse(t_no_flags *entries, t_input_data *data, t_args *input)
{
	data->d = input->valid_directories - 1;
	while (data->d >= 0)
	{
		if (input->R == '1')
		{
			if (input->argc > 1)
				ft_printf("%s:\n", data->dirs[data->d]);
			ft_capital_r(input, data->dirs[data->d], NULL);
			if (input->argc > 1 && data->d != 0)
				write(1, "\n", 1);
		}
		else
		{
			if (ft_check_rights(data) == 0 || input->l == '0')
				ft_execute(data, entries, input);
			else if (ft_check_rights(data) == -1 && input->argc > 1)
				ft_printf("%s:\n", data->dirs[data->d]);
		}
		if (data->d > 0)
			write(1, "\n", 1);
		data->d--;
	}
}

static void	ft_normal(t_no_flags *entries, t_input_data *data, t_args *arg)
{
	while (data->d < arg->valid_directories)
	{
		if (arg->R == '1')
		{
			if (arg->argc > 1)
				ft_printf("%s:\n", data->dirs[data->d]);
			ft_capital_r(arg, data->dirs[data->d], NULL);
			if (arg->argc > 1 && data->d != arg->valid_directories - 1)
				write(1, "\n", 1);
		}
		else
		{
			if (ft_check_for_read(data, arg) == 0)
			{
				if (ft_check_rights(data) == 0 || arg->l == '0')
					ft_execute(data, entries, arg);
				else if (ft_check_rights(data) == -1 && arg->argc > 1)
					ft_printf("%s:\n", data->dirs[data->d]);
			}
		}
		if (data->d < arg->valid_directories - 1)
			write(1, "\n", 1);
		data->d++;
	}
}

void	ft_handle_directories(t_input_data *data, t_args *input)
{
	t_no_flags	ls_data;

	ls_data.name = 0;
	ls_data.gr_int = 0;
	ls_data.links = 0;
	ls_data.size = 0;
	data->d = 0;
	if (input->r == '1')
		ft_reverse(&ls_data, data, input);
	else
		ft_normal(&ls_data, data, input);
}
