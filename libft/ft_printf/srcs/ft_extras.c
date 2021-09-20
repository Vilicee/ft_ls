/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:19:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:19:08 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_part_two(t_printf *data, int ret)
{
	while (data->str_len > data->len - data->negative)
	{
		write(1, "0", 1);
		data->str_len--;
		data->ret++;
		if (data->xtra > 0)
			data->xtra--;
	}
	if (data->just_dot == 1 && data->d_zero == 1)
		ret = -1;
	if (data->save_dot == 1 && data->str_len == 0 && data->d_zero == 1)
		ret = -1;
	if (data->hh == 1 && data->negative == 1)
		data->negative = 0;
	return (ret);
}

int	ft_extras(t_printf *data)
{
	int	ret;

	ret = 0;
	if (data->neg == 1)
	{
		write(1, "-", 1);
		data->neg = 0;
		if (data->just_dot == 1 || data->save_dot == 1)
			data->negative = 1;
	}
	if (data->plus == 1)
	{
		write(1, "+", 1);
		data->plus = 0;
		data->ret++;
		data->xtra--;
	}
	if (data->str_len >= data->len && data->negative == 1 && data->xtra > 0
		&& data->hh == 0)
		data->xtra++;
	return (ft_part_two(data, ret));
}
