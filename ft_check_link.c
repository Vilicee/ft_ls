/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:32:30 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/09 15:33:04 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

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
	inp->temp_ptr = ft_strcjoin(ptr, '/', inp->store);
	free(ptr);
	lstat(inp->temp_ptr, &buf);
	if (S_ISDIR(buf.st_mode))
		inp->valid_directories++;
	else
		inp->valid_directories++;
	free(inp->temp_ptr);
}

void	ft_check_link(char *argv, struct stat *buf, t_args *input)
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
