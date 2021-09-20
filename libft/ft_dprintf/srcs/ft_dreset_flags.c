/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dreset_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:18:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:44:03 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_reset_the_rest(t_data *data)
{
	data->base = 16;
	data->precision = 0;
	data->negative = 0;
	data->roundup = '0';
	data->inf = 0;
	data->nan = 0;
	data->d_or_i = 0;
	data->count = 0;
	data->ii = 0;
	data->next = '0';
	data->prec = 0;
	data->check = 0;
	data->xtra = 0;
	data->star = '0';
}

void	ft_dreset_flags(t_data *data)
{
	data->h = 0;
	data->hh = 0;
	data->l = 0;
	data->ll = 0;
	data->plus = 0;
	data->neg = 0;
	data->space = '0';
	data->zero = '0';
	data->minus = 0;
	data->hash = 0;
	data->cap_l = 0;
	data->dot = 0;
	data->num = 0;
	data->save = 0;
	data->save_dot = 0;
	data->save_neg = 0;
	data->x = 0;
	data->cap_x = 0;
	data->o = 0;
	data->u = 0;
	data->f = 0;
	data->just_dot = 0;
	data->d_zero = 0;
	data->str_len_xtra = 0;
	ft_reset_the_rest(data);
}
