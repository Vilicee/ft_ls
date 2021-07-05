/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_all_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:49:27 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/02 16:35:45 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_save_all_args(char *argv, t_input_data *data, t_args *input)
{
	if (lstat(argv, &data->stat_buf) != -1)
	{
		if (data->stat_buf.st_mode && S_ISLNK(data->stat_buf.st_mode))
		{
			if (input->l == '0')
				data->dirs[data->d++] = ft_strdup(argv);
			else
				data->fil[data->f++] = ft_strdup(argv);
		}
		else if (data->stat_buf.st_mode && S_ISDIR(data->stat_buf.st_mode))
			data->dirs[data->d++] = ft_strdup(argv);
		else if (data->stat_buf.st_mode && S_ISREG(data->stat_buf.st_mode))
			data->fil[data->f++] = ft_strdup(argv);
		else if (data->stat_buf.st_mode && S_ISCHR(data->stat_buf.st_mode))
			data->fil[data->f++] = ft_strdup(argv);
	}
	else
	{
		data->err[data->e] = ft_strdup(argv);
		data->e++;
	}
}
