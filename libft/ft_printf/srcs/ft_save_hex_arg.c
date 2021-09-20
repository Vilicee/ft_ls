/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_hex_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:32:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:23:24 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_part_two(t_printf *data)
{
	if (data->ll == 1)
	{
		data->ulln = va_arg(data->copy, unsigned long long);
		data->len = ft_hexa_len(data, data->ulln);
		if (data->ulln == 0)
			data->d_zero = 1;
	}
	if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
	{
		data->un = va_arg(data->copy, unsigned int);
		data->len = ft_hexa_len(data, data->un);
		if (data->un == 0)
			data->d_zero = 1;
	}
}

void	ft_save_hex_arg(t_printf *data)
{
	if (data->h == 1)
	{
		data->uhn = va_arg(data->copy, int);
		data->len = ft_hexa_len(data, data->uhn);
		if (data->uhn == 0)
			data->d_zero = 1;
	}
	if (data->hh == 1)
	{
		data->ohhn = va_arg(data->copy, int);
		data->len = ft_hexa_len(data, data->ohhn);
		if (data->ohhn == 0)
			data->d_zero = 1;
	}
	if (data->l == 1)
	{
		data->uln = va_arg(data->copy, long int);
		data->len = ft_hexa_len(data, data->uln);
		if (data->uln == 0)
			data->d_zero = 1;
	}
	ft_part_two(data);
}
