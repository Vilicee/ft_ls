/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nan_inf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:31:12 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:20:59 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_inf(t_printf *data)
{
	data->len = 3;
	data->zero = '0';
	if (data->plus == 1 && data->xtra > 0)
		data->xtra--;
	if (data->minus == 0)
		ft_format_float(data);
	if (data->neg == 1 && data->minus == 1)
	{
		write(1, "-", 1);
		data->ret++;
		data->neg = 0;
		if (data->xtra > 0)
			data->xtra--;
	}
	write(1, "inf", 3);
	if (data->minus == 1)
		ft_format_float(data);
	data->ret = data->ret + 3;
	free(data->deci);
	data->waste++;
}

static void	ft_nan(t_printf *data)
{
	data->len = 3;
	data->zero = '0';
	data->neg = 0;
	data->plus = 0;
	if (data->minus == 0)
		ft_format_float(data);
	write(1, "nan", 3);
	if (data->minus == 1)
		ft_format_float(data);
	data->ret = data->ret + 3;
	free(data->deci);
	data->waste++;
	ft_reset_n(data);
}

void	ft_handle_nan_inf(t_printf *data)
{
	if (data->inf == 1)
		ft_inf(data);
	if (data->nan == 1)
		ft_nan(data);
}
