/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_all_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:49:27 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 16:41:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_not_zero(char *arg, t_args *inp, char *ptr, t_input_data *data)
{
	struct stat	buf;

	while (arg[inp->i] != '\0')
		inp->i++;
	while (arg[inp->i] != '/')
		inp->i--;
	inp->store = ptr;
	free(ptr);
	ptr = ft_strndup(arg, inp->i);
	inp->temp_ptr = ft_strcjoin(ptr, '/', inp->store);
	free(ptr);
	lstat(inp->temp_ptr, &buf);
	if (S_ISDIR(buf.st_mode))
		data->dirs[data->d++] = ft_strdup(inp->temp_ptr);
	else
		data->fil[data->f++] = ft_strdup(inp->temp_ptr);
	free(inp->temp_ptr);
}

static void	ft_check_links(char *argv, t_input_data *data, t_args *input)
{
	char		*ptr;
	struct stat	buf;

	ptr = (char *)malloc(sizeof(char) * (data->stat_buf.st_size + 1));
	if (readlink(argv, ptr, data->stat_buf.st_size + 1) == -1)
		return ;
	ptr[data->stat_buf.st_size] = '\0';
	input->checker = ft_check_path(ptr, argv);
	if (input->checker == 0)
	{
		lstat(ptr, &buf);
		if (S_ISDIR(buf.st_mode))
			data->dirs[data->d++] = ft_strdup(argv);
		else
			data->fil[data->f++] = ft_strdup(argv);
		free(ptr);
	}
	else
		ft_not_zero(argv, input, ptr, data);
}

void	ft_save_all_args(char *argv, t_input_data *data, t_args *input)
{
	char		*temp;
	struct stat	t_buf;

	if (lstat(argv, &data->stat_buf) != -1)
	{
		temp = ft_check_dir_path(argv, input);
		lstat (temp, &t_buf);
		if (t_buf.st_mode && S_ISLNK(t_buf.st_mode))
		{
			if (input->l == '1' && !S_ISDIR(t_buf.st_mode))
				data->fil[data->f++] = ft_strdup(temp);
			else
				ft_check_links(temp, data, input);
		}
		else if (t_buf.st_mode && S_ISDIR(t_buf.st_mode))
			data->dirs[data->d++] = ft_strdup(argv);
		else if (t_buf.st_mode && S_ISREG(t_buf.st_mode))
			data->fil[data->f++] = ft_strdup(temp);
		else if (t_buf.st_mode && S_ISCHR(t_buf.st_mode))
			data->fil[data->f++] = ft_strdup(temp);
		free(temp);
	}
	else
		data->err[data->e++] = ft_strdup(argv);
}
