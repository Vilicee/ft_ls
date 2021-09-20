/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhandle_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:13:19 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:51:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_part_two(t_data *data)
{
	if (data->space == '1')
	{
		write(data->fd, " ", 1);
		if (data->xtra > 0)
			data->xtra--;
		data->ret++;
		data->space = '0';
	}
	if (data->save_dot == 1 && data->str_len < data->len
		&& data->d_zero == 0)
	{
		if (data->save == 1 && data->neg == 1)
			data->xtra++;
	}
	if (data->hash == 1 && data->save == 0 && data->save_dot == 0
		&& data->just_dot == 0 && data->d_zero == 1)
		data->hash = 0;
	if (data->o == 1)
	{
		if (data->d_zero == 1 && data->hash == 1
			&& data->save_dot == 0 && data->xtra > 0)
			data->hash = 0;
	}
}

static void	ft_part_three(t_data *data)
{
	int	extra;

	extra = 2;
	if (data->x == 1 || data->cap_x == 1)
	{
		if (data->hash == 1 && data->d_zero == 1 && data->o == 0)
			data->hash = 0;
	}
	if (data->hash == 1 && data->o == 1 && data->xtra > 0
		&& data->minus == 0 && data->str_len < data->len)
		data->xtra--;
	if (data->o == 0 && data->minus == 0)
	{
		if (data->hash == 1 && data->xtra > 0)
		{
			while (data->xtra > 0 && extra > 0)
			{
				data->xtra--;
				extra--;
			}
		}
	}
}

void	ft_dhandle_flags(t_data *data)
{
	if (data->plus == 1 && data->space == '1')
		data->space = '0';
	if (data->space == '1' && data->neg == 1)
		data->space = '0';
	if (data->space == 1 && data->save_dot == 1 && data->str_len == 0
		&& data->d_zero == 1)
		data->space = '0';
	if (data->zero == '1' && data->minus == 1)
		data->zero = '0';
	if (data->zero == '1' && data->just_dot == 1)
		data->zero = '0';
	if (data->zero == '1' && data->save_dot == 1)
		data->zero = '0';
	if (data->plus == 1 && data->neg == 1)
		data->plus = 0;
	if (data->u == 1 && data->plus == 1)
		data->plus = 0;
	if (data->u == 1 && data->hash == 1)
		data->hash = 0;
	if (data->u == 1 && data->space == '1')
		data->space = '0';
	ft_part_two(data);
	ft_part_three(data);
}
