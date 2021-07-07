/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:29:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/07 19:07:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*ft_check_dir_path(char *path, t_args *input)
{
	char		*temp;
	struct stat	temp_buf;
	int			i;

	i = 0;
	while (path[i] != '\0')
		i++;
	if (path[i - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		lstat(temp, &temp_buf);
		if (S_ISDIR(temp_buf.st_mode) && input->l == '0')
			return (temp);
		else
			free(temp);
	}
	temp = ft_strdup(path);
	return (temp);
}
