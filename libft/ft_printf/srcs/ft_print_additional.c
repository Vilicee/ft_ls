/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_additional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:34:22 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:22:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_part_three(t_printf *data)
{
	while (data->str_len > data->len)
	{
		if (data->neg == 1)
		{
			write(1, "-", 1);
			ft_remove_neg(data);
			data->len--;
			data->ret--;
			data->neg = 0;
		}
		else
			write(1, "0", 1);
		data->str_len--;
		data->ret++;
		data->str_len_xtra++;
	}
	return (0);
}

static int	ft_part_two(t_printf *data)
{
	if (data->neg == 1)
		data->len--;
	if (data->save_dot == 1 && data->d_zero == 1 && data->u != 1)
	{
		if (data->save == 0)
		{
			if (data->hash != 1 && data->x != 1 && data->cap_x != 1)
				data->waste++;
			return (-1);
		}
		if (data->str_len == 0)
		{
			if (data->o == 0)
				write(1, " ", 1);
			if (data->x == 1 || data->cap_x == 1)
				data->ret++;
			return (-1);
		}
	}
	return (ft_part_three(data));
}

int	ft_print_additional(t_printf *data)
{
	if (data->just_dot == 1 && data->d_zero == 1)
	{
		if (data->save == 1 || data->space == '1')
		{
			write(1, " ", 1);
			data->ret++;
		}
		if (data->hash != 1 && data->x != 1 && data->cap_x != 1)
			data->waste++;
		return (-1);
	}
	if (data->space == '1' && data->plus == 0 && data->neg == 0)
	{
		write(1, " ", 1);
		data->ret++;
		if (data->xtra > 0)
			data->xtra--;
	}
	if (data->plus == 1 && data->neg == 0)
	{
		write(1, "+", 1);
		data->ret++;
	}
	return (ft_part_two(data));
}
