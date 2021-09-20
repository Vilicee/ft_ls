/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:27:33 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:23:16 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_case_uns_part_two(t_printf*data)
{
	if (data->h == 1)
	{
		data->uhn = va_arg(data->copy, int);
		if (data->uhn < 0)
			data->uhn = 65535 + data->uhn;
		data->len = ft_intlen(data->uhn);
		if (data->uhn == 0)
			data->d_zero = 1;
	}
	if (data->ll == 1 || data->l == 1)
	{
		data->ulln = va_arg(data->copy, unsigned long long);
		data->len = ft_uns_longlong_len(data->ulln);
		if (data->ulln == 0)
			data->d_zero = 1;
	}
	if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
	{
		data->un = va_arg(data->copy, unsigned int);
		data->len = ft_uns_longlong_len(data->un);
		if (data->un == 0)
			data->d_zero = 1;
	}
}

static void	ft_case_unsigned(t_printf*data)
{
	if (data->hh == 1)
	{
		data->uhhn = va_arg(data->copy, int);
		if (data->uhhn < 0)
		{
			while (data->uhhn < 0)
				data->uhhn = 256 + data->uhhn;
		}
		if (data->uhhn > 256)
		{
			while (data->uhhn > 256)
				data->uhhn = data->uhhn - 256;
		}
		data->len = ft_intlen(data->uhhn);
		if (data->uhhn == 0)
			data->d_zero = 1;
	}
	ft_case_uns_part_two(data);
}

static void	ft_other_cases_part_two(t_printf*data)
{
	if (data->ll == 1 || data->l == 1)
	{
		data->lln = va_arg(data->copy, long long);
		data->len = ft_long_long_len(data->lln);
		if (data->lln == 0)
			data->d_zero = 1;
	}
	if (data->ll == 0 && data->l == 0 && data->h == 0 && data->hh == 0)
	{
		data->n = va_arg(data->copy, int);
		data->len = ft_intlen(data->n);
		if (data->n == 0)
			data->d_zero = 1;
	}
}

void	ft_save_arg(t_printf*data)
{
	if (data->u == 1)
		ft_case_unsigned(data);
	else
	{
		if (data->h == 1)
		{
			data->hn = va_arg(data->copy, int);
			data->len = ft_intlen(data->hn);
			if (data->hn == 0)
				data->d_zero = 1;
			if (data->hn > 32767)
				data->len++;
		}
		if (data->hh == 1)
		{
			data->hhn = va_arg(data->copy, int);
			data->len = ft_intlen(data->hhn);
			if (data->hhn == 0)
				data->d_zero = 1;
		}
		ft_other_cases_part_two(data);
	}
}
