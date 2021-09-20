/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:13:04 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:21:41 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_part_two(t_printf *data)
{
	if (data->plus == 1 || data->neg == 1)
		data->xtra--;
	while (data->xtra > (data->str_len + data->str_len_xtra))
	{
		if (data->zero == '1' && data->save == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->xtra--;
		data->ret++;
		data->space = '0';
	}
}

static void	ft_zero_true(t_printf *data)
{
	if (data->plus == 1 && data->neg == 0)
	{
		write(1, "+", 1);
		data->plus = 0;
		data->space = '0';
	}
	else if (data->save_neg != 1)
		write(1, "0", 1);
	if (data->save_neg == 1)
	{
		write(1, "-", 1);
		data->len--;
		data->ret--;
		data->save_neg = 0;
		ft_remove_neg(data);
	}
}

static void	ft_xtra(t_printf *data)
{
	if (data->plus == 1 && data->zero == '0')
		data->xtra--;
	if (data->save_neg == 1)
		data->xtra--;
	while ((data->xtra - data->str_len_xtra) > data->len)
	{
		if (data->zero == '1')
			ft_zero_true(data);
		else
			write(1, " ", 1);
		data->xtra--;
		data->ret++;
		data->space = '0';
	}
}

void	ft_int_format(t_printf *data)
{
	if (data->hash == 1 && data->d_zero != 1 && data->f == 0)
	{
		if (data->base == 16)
			data->xtra = data->xtra - 2;
		else
			data->xtra--;
	}
	if (data->hash == 1 && data->zero == '1' && data->f == 0)
		ft_handle_hash(data);
	if (data->space == '1' && data->plus == 0 && data->save == 1)
	{
		write(1, " ", 1);
		if (data->xtra > 1)
			data->xtra--;
		data->ret++;
		data->space = '0';
	}
	if (data->str_len < data->len)
		ft_xtra(data);
	else
		ft_part_two(data);
}
