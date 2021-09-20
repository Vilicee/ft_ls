/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:27:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:22:35 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_initialize_index_two(t_printf *data)
{
	data->x = 0;
	data->cap_x = 0;
	data->id = 0;
	data->h = 0;
	data->hh = 0;
	data->l = 0;
	data->ll = 0;
	data->cap_l = 0;
	data->base = 16;
	data->u = 0;
	data->o = 0;
	data->f = 0;
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
	data->star = '0';
}

static void	ft_initialize_index(t_printf *data)
{
	data->i = 0;
	data->c_count = 0;
	data->ret = 0;
	data->space = '0';
	data->zero = '0';
	data->minus = 0;
	data->save_neg = 0;
	data->plus = 0;
	data->neg = 0;
	data->dot = 0;
	data->hash = 0;
	data->num = 0;
	data->save = 0;
	data->save_dot = 0;
	data->xtra = 0;
	data->str_len = 0;
	data->str_len_xtra = 0;
	data->len = 0;
	data->waste = 0;
	data->just_dot = 0;
	data->d_zero = 0;
	ft_initialize_index_two(data);
}

int	ft_printf(const char *format, ...)
{
	t_printf	data;

	va_start(data.copy, format);
	ft_initialize_index(&data);
	ft_validate_flags(format, &data);
	ft_initialize_index(&data);
	data.c_count = ft_format_str(format, &data);
	va_end(data.copy);
	return (data.c_count);
}
