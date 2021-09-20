/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dunsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:18:15 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:40:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_print_int(t_data *data)
{
	if (ft_dextras(data) == -1)
	{
		if (data->save == 0)
			data->ret--;
		else
			write(data->fd, " ", 1);
		return ;
	}
	ft_dremove_neg(data);
	if (data->neg == 1)
		write(data->fd, "-", 1);
	if (data->h == 1)
		ft_putnbr_fd(data->uhn, data->fd);
	if (data->hh == 1)
		ft_putnbr_fd(data->uhhn, data->fd);
	if (data->ll == 1 || data->l == 1)
		ft_put_uns_ll_fd(data->ulln, data->fd);
	if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
		ft_put_uns_ll_fd(data->un, data->fd);
}

static void	ft_i(t_data *data)
{
	if (data->minus == 1)
	{
		ft_print_int(data);
		data->minus = 2;
	}
	ft_dformat_diu(data);
	if (data->minus == 0)
		ft_print_int(data);
}

void	ft_dunsigned_int(t_data *data)
{
	ft_dreset_n(data);
	ft_dsave_arg(data);
	data->ret = data->ret + data->len;
	ft_dcheck_for_negative(data);
	ft_dhandle_flags(data);
	ft_i(data);
	data->waste++;
	ft_dreset_n(data);
}
