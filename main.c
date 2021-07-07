/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:05:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/07 13:03:00 by wvaara           ###   ########.fr       */
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
	input->i = 0;
	input->options = '0';
	input->l = '0';
	input->dir_input = '0';
}

static void	ft_not_zero(char *arg, t_args *inp, char *ptr)
{
	struct stat	buf;
	
	while (arg[inp->i] != '\0')
		inp->i++;
	while (arg[inp->i] != '/')
		inp->i--;
	inp->store = ptr;
	free(ptr);
	ptr = ft_strndup(arg, inp->i);
	inp->temp_ptr = ft_strcjoin(ptr, '/' ,inp->store);
	free(ptr);
	lstat(inp->temp_ptr, &buf);
	if (S_ISDIR(buf.st_mode))
		inp->valid_directories++;
	else
		inp->valid_directories++;
	free(inp->temp_ptr);
}

static void	ft_check_link(char *argv, struct stat *buf, t_args *input)
{
	char		*ptr;
	struct stat	buffer;
	
	ptr = (char *)malloc(sizeof(char) * (buf->st_size + 1));
	readlink(argv, ptr, buf->st_size + 1);
	ptr[buf->st_size] = '\0';
	input->checker = ft_check_path(ptr, argv);
	if (input->checker == 0)
	{
		lstat(ptr, &buffer);
		if (S_ISDIR(buffer.st_mode))
			input->valid_directories++;
		else
			input->valid_files++;
		free(ptr);
	}
	else
		ft_not_zero(argv, input, ptr);
}

static int	ft_parse_and_count(char *argv, struct stat *buf, t_args *input)
{
	if (lstat(argv, buf) != -1)
	{
		if (buf->st_mode && S_ISLNK(buf->st_mode))
			ft_check_link(argv, buf, input);
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
		while (argv[i] != NULL)
			if (ft_parse_and_count(argv[i++], &buf, &input) == -1)
				return (-1);
		i = ft_reserve_memory(&input, &data);
		input.i = 0;
		while (argv[i] != NULL)
			ft_save_all_args(argv[i++], &data, &input);
		data.i = data.d + data.e + data.f;
		if (data.i > 0)
			ft_organize_args(&data, &input);
		ft_ls(&data, &input);
	}
	system("leaks a.out");
	return (0);
}
