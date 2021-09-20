/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daddress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:50:42 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:17:06 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_p(t_data *data, void *ptr, int len)
{
	if (data->minus == 1)
		ft_putaddr_fd(ptr, data->fd);
	while (data->xtra > len)
	{
		write(data->fd, " ", 1);
		data->xtra--;
		data->ret++;
	}
	if (data->minus == 0)
		ft_putaddr_fd(ptr, data->fd);
	data->minus = 0;
}

void	ft_daddress(t_data *data)
{
	void	*ptr;
	int		len;

	ptr = va_arg(data->copy, void *);
	len = ft_addr_len(ptr);
	if (len == 10)
	{
		if (data->xtra > 0)
		{
			data->xtra--;
			data->ret++;
		}
		else
			data->ret++;
	}
	if (data->save == 1)
		ft_p(data, ptr, len);
	else
		ft_putaddr_fd(ptr, data->fd);
	data->waste++;
	data->ret = data->ret + len;
}
