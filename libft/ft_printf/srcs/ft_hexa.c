/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:31:03 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:21:21 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_hexa(t_printf *data)
{
	if (ft_extras(data) == -1)
	{
		if (data->save == 1 && data->hash == 0)
		{
			write(1, " ", 1);
			data->ret++;
		}
		return ;
	}
	if (data->neg == 1)
		ft_negative_hex(data);
	else
	{
		if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
			ft_hexadecimal(data, data->un);
		if (data->h == 1)
			ft_hexadecimal(data, data->uhn);
		if (data->hh == 1)
			ft_hexadecimal(data, data->ohhn);
		if (data->l == 1)
			ft_hexadecimal(data, data->uln);
		if (data->ll == 1)
			ft_hexadecimal(data, data->ulln);
	}
}

static void	ft_i(t_printf *data)
{
	if (data->minus == 1)
	{
		if (data->hash == 1)
			ft_handle_hash(data);
		ft_print_hexa(data);
		data->minus = 2;
	}
	ft_format_diu(data);
	if (data->minus == 0)
	{
		if (data->hash == 1)
			ft_handle_hash(data);
		ft_print_hexa(data);
	}
}

void	ft_hexa(t_printf *data)
{
	ft_reset_n(data);
	ft_save_hex_arg(data);
	ft_check_for_negative(data);
	ft_handle_flags(data);
	ft_i(data);
	ft_reset_n(data);
	data->waste++;
}
