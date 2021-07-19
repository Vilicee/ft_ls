/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:10:22 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/19 13:08:49 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_count_entries(void)
{
	struct dirent	*entry;
	int				ret;
	DIR				*dir;

	ret = 0;
	dir = opendir(".");
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_name[0] != '.')
			ret++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (ret);
}

static int	ft_save_ent(t_no_flags *data)
{
	struct dirent	*temp;

	data->dir = opendir(".");
	data->i = 0;
	data->files = ft_count_entries();
	data->entry = (char **)(malloc(sizeof(char *)
				* (data->files + 1)));
	if (!data->entry)
	{
		ft_printf("Malloc error, try again\n");
		return (-1);
	}
	while (data->i < data->files)
	{
		temp = readdir(data->dir);
		if (temp->d_name[0] != '.')
		{
			data->entry[data->i] = temp->d_name;
			data->i++;
		}
	}
	data->entry[data->i] = NULL;
	closedir(data->dir);
	return (0);
}

static void	ft_print(t_no_flags *data)
{
	data->i = 0;
	while (data->i < data->files)
	{
		ft_printf("%s\n", data->entry[data->i]);
		data->i++;
	}
	free(data->entry);
}

void	ft_no_flags(void)
{
	t_no_flags	data;

	if (ft_save_ent(&data) == -1)
		return ;
	ft_ascii_order(&data);
	ft_print(&data);
}
