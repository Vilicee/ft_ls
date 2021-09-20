/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:31:03 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:53:04 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_print_hexa(t_data *data)
{
	if (ft_dextras(data) == -1)
	{
		if (data->save == 1 && data->hash == 0)
		{
			write(data->fd, " ", 1);
			data->ret++;
		}
		return ;
	}
	if (data->neg == 1)
		ft_dnegative_hex(data);
	else
	{
		if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
			ft_dhexadecimal(data, data->un);
		if (data->h == 1)
			ft_dhexadecimal(data, data->uhn);
		if (data->hh == 1)
			ft_dhexadecimal(data, data->ohhn);
		if (data->l == 1)
			ft_dhexadecimal(data, data->uln);
		if (data->ll == 1)
			ft_dhexadecimal(data, data->ulln);
	}
}

static void	ft_i(t_data *data)
{
	if (data->minus == 1)
	{
		if (data->hash == 1)
			ft_dhandle_hash(data);
		ft_print_hexa(data);
		data->minus = 2;
	}
	ft_dformat_diu(data);
	if (data->minus == 0)
	{
		if (data->hash == 1)
			ft_dhandle_hash(data);
		ft_print_hexa(data);
	}
}

void	ft_dhexa(t_data *data)
{
	ft_dreset_n(data);
	ft_dsave_hex_arg(data);
	ft_dcheck_for_negative(data);
	ft_dhandle_flags(data);
	ft_i(data);
	ft_dreset_n(data);
	data->waste++;
}
