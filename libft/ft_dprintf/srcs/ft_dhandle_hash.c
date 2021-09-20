/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhandle_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:48:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:51:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_base_eigth(t_data *data)
{
	if (data->base == 8)
	{
		write(data->fd, "0", 1);
		data->ret++;
		if (data->minus == 0)
			data->xtra++;
		if (data->str_len > data->len)
			data->str_len--;
		if (data->xtra > 1)
			data->xtra--;
	}
}

void	ft_dhandle_hash(t_data *data)
{
	int	extra;

	extra = 2;
	if (data->base == 16)
	{
		if (data->x == 1)
			write(data->fd, "0x", 2);
		else
			write(data->fd, "0X", 2);
		data->ret = data->ret + 2;
		if (data->minus == 1)
		{
			while (data->xtra > 0 && extra > 0)
			{
				data->xtra--;
				extra--;
			}
		}
	}
	ft_base_eigth(data);
}
