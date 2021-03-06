/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_entries.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:59:34 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/19 13:09:53 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_count_entries(char *path, t_args *input)
{
	struct dirent	*e;
	int				ret;
	DIR				*dir;

	ret = 0;
	dir = opendir(path);
	e = readdir(dir);
	while (e)
	{
		if (e->d_name[0] != '.' || (e->d_name[0] == '.' && input->a == '1'))
			ret++;
		e = readdir(dir);
	}
	closedir(dir);
	return (ret);
}

static void	ft_set_values(t_no_flags *data, char *path, t_args *input)
{
	data->i = 0;
	data->files = ft_count_entries(path, input);
	data->entry = (char **)(malloc(sizeof(char *) * (data->files + 1)));
	data->total = 0;
	data->links = 0;
	data->name = 0;
	data->size = 0;
	data->gr_int = 0;
}

static void	ft_total_blocks(char *name, char *path, t_no_flags *data)
{
	char			*temp;
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*temp2;

	temp = ft_strcjoin(path, '/', name);
	if (lstat(temp, &buf) == -1)
	{
		free(temp);
		return ;
	}
	pwd = getpwuid(buf.st_uid);
	temp2 = getgrgid(buf.st_gid);
	if (pwd && data->name < (int)ft_strlen(pwd->pw_name))
		data->name = (int)ft_strlen(pwd->pw_name);
	if (temp2 && data->gr_int < (int)ft_strlen(temp2->gr_name))
		data->gr_int = (int)ft_strlen(temp2->gr_name);
	data->total = data->total + buf.st_blocks;
	if (data->links < buf.st_nlink)
		data->links = (int)buf.st_nlink;
	if (data->size < buf.st_size)
		data->size = buf.st_size;
	free(temp);
}

static void	ft_save(char *path, t_args *input, t_no_flags *data)
{
	struct dirent	*tm;
	DIR				*dir;

	dir = opendir(path);
	tm = readdir(dir);
	while (tm)
	{
		if (tm->d_name[0] != '.' || (tm->d_name[0] == '.' && input->a == '1'))
		{
			data->entry[data->i] = ft_strdup(tm->d_name);
			ft_total_blocks(data->entry[data->i], path, data);
			data->i++;
		}
		tm = readdir(dir);
	}
	data->entry[data->i] = NULL;
	closedir(dir);
}

int	ft_save_entries(t_no_flags *data, t_args *input, char *path)
{
	struct stat		buf;
	DIR				*dir;

	dir = opendir(path);
	input->file = '0';
	if (!dir)
	{
		ft_parse_output(path, &buf, input);
		return (-1);
	}
	closedir(dir);
	ft_set_values(data, path, input);
	if (!data->entry)
		return (-1);
	ft_save(path, input, data);
	return (0);
}
