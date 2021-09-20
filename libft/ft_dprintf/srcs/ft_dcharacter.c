/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcharacter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:42:07 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:35:24 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_c(t_data *data)
{
	int	temp;

	temp = va_arg(data->copy, int);
	data->len = ft_intlen(temp);
	if (data->minus == 1)
		ft_putchar_fd((char)temp, data->fd);
	while (data->xtra > 1)
	{
		write(data->fd, " ", 1);
		data->xtra--;
		data->ret++;
	}
	if (data->minus == 0)
		ft_putchar_fd((char)temp, data->fd);
	data->minus = 0;
}

void	ft_dcharacter(t_data *data)
{
	if (data->save == 1)
		ft_c(data);
	else
		ft_putchar_fd((char)va_arg(data->copy, int), data->fd);
	data->waste++;
	data->ret++;
}
