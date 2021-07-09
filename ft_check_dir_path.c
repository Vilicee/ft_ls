/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:29:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/08 16:19:01 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_verify_name(char *path)
{
	struct stat	buf;

	lstat(path, &buf);
	if (buf.st_mode && S_ISREG(buf.st_mode))
		return (0);
	if (buf.st_mode && S_ISCHR(buf.st_mode))
		return (0);
	return (-1);
}

char	*ft_check_dir_path(char *path, t_args *input)
{
	char		*temp;
	struct stat	temp_buf;
	int			i;
	DIR			*dir;

	i = 0;
	while (path[i] != '\0')
		i++;
	if (path[i - 1] != '/')
	{
		if (ft_verify_name(path) == -1)
		{
			temp = ft_strjoin(path, "/");
			lstat(temp, &temp_buf);
			if (S_ISDIR(temp_buf.st_mode) && input->l == '0')
			{
				dir = opendir(temp);
				if (dir)
				{
					closedir(dir);
					return (temp);
				}
			}
			else
				free(temp);
		}
	}
	temp = ft_strdup(path);
	return (temp);
}
