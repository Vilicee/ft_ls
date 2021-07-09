/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:06:31 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/09 15:29:25 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_parse_output(char *path, struct stat *buf, t_args *input)
{
	lstat(path, buf);
	if (buf->st_mode && S_ISDIR(buf->st_mode))
	{
		if (input->argc > 1 && input->R == '0')
			ft_printf("ft_ls: : Permission denied\n");
		else if (input->argc > 1 && input->R == '1')
			ft_printf("ft_ls: : Permission denied\n", path);
		else if (input->argc == 1 && input->R == '1')
		{
			ft_printf("\n%s:\n", path);
			input->argc = 0;
		}
		else if (input->argc == 0 && input->R == '1')
			ft_printf("\n%s:\n", path);
		else
			ft_putendl("ft_ls: : Permission denied");
	}
	else
	{
		if (S_ISLNK(buf->st_mode) && input->R == '1')
			input->file = '1';
		input->argc = 1;
	}
}
