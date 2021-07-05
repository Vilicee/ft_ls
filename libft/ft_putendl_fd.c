/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:12:07 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:01:47 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *str, int fd)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			i++;
		}
		write(fd, str, i);
		write(fd, "\n", 1);
	}
}
