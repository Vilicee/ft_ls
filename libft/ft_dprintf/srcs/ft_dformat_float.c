/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dformat_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:20:56 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:35:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_part_three(t_data *data)
{
	if (data->neg == 1)
	{
		write(data->fd, "-", 1);
		data->ret++;
	}
	if (data->plus == 1 && data->inf == 1)
	{
		write(data->fd, "+", 1);
		data->ret++;
		if (data->xtra > 0)
			data->xtra--;
	}
}

static void	ft_part_two(t_data *data)
{
	while (data->xtra > data->str_len_xtra + data->neg)
	{
		if (data->neg == 1 && data->zero == '1')
		{
			write(data->fd, "-", 1);
			data->neg = 0;
		}
		else if (data->zero == '1')
			write(data->fd, "0", 1);
		else
			write(data->fd, " ", 1);
		data->xtra--;
		data->ret++;
	}
}

void	ft_dformat_float(t_data *data)
{
	if (data->plus == 1 && data->inf == 0)
	{
		write(data->fd, "+", 1);
		data->ret++;
		if (data->xtra > 0)
			data->xtra--;
	}
	data->str_len_xtra = data->len;
	if (data->just_dot == 1 && data->d_zero == 1 && data->plus == 1)
		data->xtra++;
	if (data->save_dot == 1 && data->str_len == 0 && data->d_zero == 1
		&& data->plus == 1)
		data->xtra++;
	ft_part_two(data);
	ft_part_three(data);
}
