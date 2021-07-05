/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:05:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/05 17:01:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_initialize_variables(t_args *input, t_input_data *data)
{
	input->valid_flag = '0';
	input->errors = 0;
	input->valid_directories = 0;
	input->valid_files = 0;
	data->e = 0;
	data->f = 0;
	data->d = 0;
	data->i = 0;
	input->a = '0';
	input->options = '0';
	input->l = '0';
	input->dir_input = '0';
}

static int	ft_parse_and_count(char *argv, struct stat *buf, t_args *input)
{
	if (lstat(argv, buf) != -1)
	{
		if (buf->st_mode && S_ISLNK(buf->st_mode))
		{
			if (input->l == '0')
				input->valid_directories++;
			else
				input->valid_files++;
		}
		else if (buf->st_mode && S_ISDIR(buf->st_mode))
			input->valid_directories++;
		else if (buf->st_mode && S_ISREG(buf->st_mode))
			input->valid_files++;
		else if (buf->st_mode && S_ISCHR(buf->st_mode))
			input->valid_files++;
		input->valid_flag = '1';
	}
	else
		if (ft_parse_args(input, argv) == -1)
			return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	t_args			input;
	t_input_data	data;
	struct stat		buf;

	i = 1;
	ft_initialize_variables(&input, &data);
	if (argc == 1)
		ft_no_flags();
	if (argc >= 2)
	{
		while (argv[i] != '\0')
			if (ft_parse_and_count(argv[i++], &buf, &input) == -1)
				return (-1);
		i = ft_reserve_memory(&input, &data);
		while (argv[i] != '\0')
			ft_save_all_args(argv[i++], &data, &input);
		data.i = data.d + data.e + data.f;
		if (data.i > 0)
			ft_organize_args(&data, &input);
		ft_ls(&data, &input);
	}
	return (0);
}
