/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:45:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:19:25 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_part_four(const char *format, t_printf *data)
{
	if (format[data->i] == '.')
	{
		if (ft_isdigit(format[data->i + 1]) == 1)
			data->dot = 1;
		else
			data->just_dot = 1;
		return (0);
	}
	if (format[data->i] == '*')
	{
		data->star = '1';
		return (0);
	}
	return (-1);
}

static int	ft_part_three(const char *format, t_printf *data)
{
	if (format[data->i] == 'l')
	{
		if (format[data->i + 1] == 'l')
		{
			data->ll = 1;
			data->waste++;
			data->i++;
		}
		else
			data->l = 1;
		return (0);
	}
	if (format[data->i] == 'L')
	{
		data->cap_l = 1;
		return (0);
	}
	return (ft_part_four(format, data));
}

static int	ft_part_two(const char *format, t_printf *data)
{
	if (format[data->i] == '#')
	{
		data->hash = 1;
		return (0);
	}
	if (format[data->i] == 'h')
	{
		if (format[data->i + 1] == 'h')
		{
			data->hh = 1;
			data->i++;
			data->waste++;
		}
		else
			data->h = 1;
		return (0);
	}
	return (ft_part_three(format, data));
}

int	ft_flags(const char *format, t_printf *data)
{
	if (format[data->i] == ' ')
	{
		data->space = '1';
		return (0);
	}
	if (format[data->i] == '0' && format[data->i - 1] != '.'
		&& ft_isdigit(format[data->i - 1]) != 1)
		data->zero = '1';
	if (ft_isdigit(format[data->i]) == 1)
	{
		data->num = 1;
		return (0);
	}
	if (format[data->i] == '-')
	{
		data->minus = 1;
		return (0);
	}
	if (format[data->i] == '+')
	{
		data->plus = 1;
		return (0);
	}
	return (ft_part_two(format, data));
}
