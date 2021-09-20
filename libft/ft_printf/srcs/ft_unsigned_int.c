/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:18:15 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:23:56 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_int(t_printf *data)
{
	if (ft_extras(data) == -1)
	{
		if (data->save == 0)
			data->ret--;
		else
			write(1, " ", 1);
		return ;
	}
	ft_remove_neg(data);
	if (data->neg == 1)
		write(1, "-", 1);
	if (data->h == 1)
		ft_putnbr(data->uhn);
	if (data->hh == 1)
		ft_putnbr(data->uhhn);
	if (data->ll == 1 || data->l == 1)
		ft_put_uns_longlong(data->ulln);
	if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
		ft_put_uns_longlong(data->un);
}

static void	ft_i(t_printf *data)
{
	if (data->minus == 1)
	{
		ft_print_int(data);
		data->minus = 2;
	}
	ft_format_diu(data);
	if (data->minus == 0)
		ft_print_int(data);
}

void	ft_unsigned_int(t_printf *data)
{
	ft_reset_n(data);
	ft_save_arg(data);
	data->ret = data->ret + data->len;
	ft_check_for_negative(data);
	ft_handle_flags(data);
	ft_i(data);
	data->waste++;
	ft_reset_n(data);
}
