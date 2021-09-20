/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:48:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:20:34 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_base_eigth(t_printf *data)
{
	if (data->base == 8)
	{
		write(1, "0", 1);
		data->ret++;
		if (data->minus == 0)
			data->xtra++;
		if (data->str_len > data->len)
			data->str_len--;
		if (data->xtra > 1)
			data->xtra--;
	}
}

void	ft_handle_hash(t_printf *data)
{
	int	extra;

	extra = 2;
	if (data->base == 16)
	{
		if (data->x == 1)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
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
