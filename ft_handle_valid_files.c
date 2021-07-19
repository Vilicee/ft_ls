/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_valid_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:39:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/19 12:50:46 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_measure_format(t_no_flags *fl, t_input_data *dt, t_args *input)
{
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*party;

	while (dt->f < input->valid_files)
	{
		if (lstat(dt->fil[dt->f], &buf) == -1)
			dt->f++;
		else
		{
			pwd = getpwuid(buf.st_uid);
			party = getgrgid(buf.st_gid);
			if (pwd && fl->name < (int)ft_strlen(pwd->pw_name))
				fl->name = (int)ft_strlen(pwd->pw_name);
			if (party && fl->gr_int < (int)ft_strlen(party->gr_name))
				fl->gr_int = (int)ft_strlen(party->gr_name);
			if (fl->links < buf.st_nlink)
				fl->links = (int)buf.st_nlink;
			if (fl->size < buf.st_size)
				fl->size = buf.st_size;
			dt->f++;
		}
	}
}

static void	ft_reverse(t_no_flags *ls_data, t_input_data *data, t_args *input)
{
	data->f = input->valid_files - 1;
	while (data->f >= 0)
	{
		if (input->l == '1')
			ft_file_stat(data->fil[data->f], ls_data);
		if (ls_data->l == '1')
			ft_modify_file(data->fil[data->f], data);
		ft_printf("%s", data->fil[data->f]);
		if (data->f != 0)
			write(1, "\n", 1);
		data->f--;
	}
}

static void	ft_normal(t_no_flags *ls_data, t_input_data *data, t_args *input)
{
	while (data->f < input->valid_files)
	{
		if (input->l == '1')
			ft_file_stat(data->fil[data->f], ls_data);
		if (ls_data->l == '1')
			ft_modify_file(data->fil[data->f], data);
		ft_printf("%s", data->fil[data->f]);
		if (data->f < input->valid_files - 1)
			write(1, "\n", 1);
		data->f++;
	}
}

void	ft_handle_valid_files(t_input_data *data, t_args *input)
{	
	t_no_flags	ls_data;

	data->f = 0;
	ls_data.name = 0;
	ls_data.links = 0;
	ls_data.size = 0;
	ls_data.gr_int = 0;
	ft_measure_format(&ls_data, data, input);
	data->f = 0;
	if (input->r == '1')
		ft_reverse(&ls_data, data, input);
	else
		ft_normal(&ls_data, data, input);
	write(1, "\n", 1);
	if (input->valid_directories > 0)
		write(1, "\n", 1);
}
