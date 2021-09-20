/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhandle_nan_inf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:31:12 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 14:09:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_inf(t_data *data)
{
	data->len = 3;
	data->zero = '0';
	if (data->plus == 1 && data->xtra > 0)
		data->xtra--;
	if (data->minus == 0)
		ft_dformat_float(data);
	if (data->neg == 1 && data->minus == 1)
	{
		write(data->fd, "-", 1);
		data->ret++;
		data->neg = 0;
		if (data->xtra > 0)
			data->xtra--;
	}
	write(data->fd, "inf", 3);
	if (data->minus == 1)
		ft_dformat_float(data);
	data->ret = data->ret + 3;
	ft_memdel((void *)&data->deci);
	data->waste++;
}

static void	ft_nan(t_data *data)
{
	data->len = 3;
	data->zero = '0';
	data->neg = 0;
	data->plus = 0;
	if (data->minus == 0)
		ft_dformat_float(data);
	write(data->fd, "nan", 3);
	if (data->minus == 1)
		ft_dformat_float(data);
	data->ret = data->ret + 3;
	ft_memdel((void *)&data->deci);
	data->waste++;
	ft_dreset_n(data);
}

void	ft_dhandle_nan_inf(t_data *data)
{
	if (data->inf == 1)
		ft_inf(data);
	if (data->nan == 1)
		ft_nan(data);
}
