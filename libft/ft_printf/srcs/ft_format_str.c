/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:00:23 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:20:05 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_find_specifier_two(const char *format, t_printf *data)
{
	if (format[data->i] == 'o')
	{
		data->base = 8;
		data->x = 1;
		data->o = 1;
		ft_hexa(data);
	}
	if (format[data->i] == 'u')
	{
		data->u = 1;
		ft_unsigned_int(data);
	}
	if (format[data->i] == 'f')
	{
		ft_float(data);
	}
}

static void	ft_find_specifier(const char *format, t_printf *data)
{
	if (format[data->i] == 's')
		ft_string(data);
	if (format[data->i] == 'c')
		ft_character(data);
	if (format[data->i] == 'p')
		ft_address(data);
	if (format[data->i] == 'd' || format[data->i] == 'i')
	{
		data->d_or_i = 1;
		ft_int(data);
	}
	if (format[data->i] == '%')
		ft_percentage(data);
	if (format[data->i] == 'x')
	{
		data->x = 1;
		ft_hexa(data);
	}
	if (format[data->i] == 'X')
	{
		data->cap_x = 1;
		ft_hexa(data);
	}
	ft_find_specifier_two(format, data);
}

static void	ft_save_int(const char *format, t_printf *data)
{
	if (data->dot == 1)
	{
		data->str_len = ft_adhoc_atoi(format, data);
		data->save_dot = 1;
	}
	if (data->dot == 0)
	{
		data->save = 1;
		data->xtra = ft_adhoc_atoi(format, data);
	}
	data->i--;
	data->waste--;
	data->num = 0;
	data->dot = 0;
}

static void	ft_print_flag(const char *format, t_printf *data)
{
	data->i++;
	data->waste++;
	while (format[data->i] != '\0')
	{
		if (ft_specifiers(format, data) == 0)
			break ;
		ft_flags(format, data);
		if (data->num == 1)
			ft_save_int(format, data);
		data->i++;
		data->waste++;
	}
	if (data->star == '1')
		data->xtra = va_arg(data->copy, int);
	ft_find_specifier(format, data);
	ft_reset_flags(data);
}

int	ft_format_str(const char *format, t_printf *data)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (format[data->i] != '\0')
	{
		start = data->i;
		while (format[data->i] != '%' && format[data->i] != '\0')
			data->i++;
		if (data->i != 0)
			write(1, &format[start], data->i - start);
		if (format[data->i] == '%' && format[data->i + 1] != '\0' \
			&& data->flag[i] == 0)
			ft_print_flag(format, data);
		if (format[data->i] == '%' && data->flag[i] == -1)
			data->waste++;
		if (format[data->i] != '\0')
			data->i++;
	}
	data->i = data->i - data->waste + data->ret;
	return (data->i);
}
