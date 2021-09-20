/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:43 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:19:47 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_part_two(t_printf *data)
{
	if (data->str_len > data->len)
		data->str_len_xtra = data->str_len;
	else
		data->str_len_xtra = data->len;
	if (data->just_dot == 1 && data->d_zero == 1 && data->plus == 1)
		data->xtra++;
	if (data->save_dot == 1 && data->str_len == 0 && data->d_zero == 1
		&& data->plus == 1)
		data->xtra++;
	while (data->xtra > data->str_len_xtra + data->neg + data->negative)
	{
		if (data->neg == 1 && data->zero == '1')
		{
			write(1, "-", 1);
			data->neg = 0;
		}
		if (data->zero == '1')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->xtra--;
		data->ret++;
	}
}

void	ft_format_diu(t_printf *data)
{
	if (data->x == 1 || data->cap_x == 1 || data->o == 1)
	{
		if (data->hash == 1 && data->zero == '1')
		{
			ft_handle_hash(data);
			data->hash = 0;
		}
	}
	if (data->plus == 1 && data->zero == '1')
	{
		write(1, "+", 1);
		data->plus = 0;
		data->ret++;
		if (data->xtra > 0)
			data->xtra--;
	}
	else if (data->plus == 1 && data->zero == '0')
		data->xtra--;
	if (data->d_zero == 0 && data->just_dot == 1)
		data->xtra--;
	if (data->save_dot == 0 && data->xtra > 0 && data->zero == '0'
		&& data->neg == 1)
		data->xtra++;
	ft_part_two(data);
}
