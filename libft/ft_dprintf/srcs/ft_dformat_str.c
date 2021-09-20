/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dformat_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:00:23 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 12:07:33 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_find_specifier_two(const char *format, t_data *data)
{
	if (format[data->i] == 'o')
	{
		data->base = 8;
		data->x = 1;
		data->o = 1;
		ft_dhexa(data);
	}
	if (format[data->i] == 'u')
	{
		data->u = 1;
		ft_dunsigned_int(data);
	}
	if (format[data->i] == 'f')
	{
		ft_dfloat(data);
	}
}

static void	ft_find_specifier(const char *format, t_data *data)
{
	if (format[data->i] == 's')
		ft_dstring(data);
	if (format[data->i] == 'c')
		ft_dcharacter(data);
	if (format[data->i] == 'p')
		ft_daddress(data);
	if (format[data->i] == 'd' || format[data->i] == 'i')
	{
		data->d_or_i = 1;
		ft_dint(data);
	}
	if (format[data->i] == '%')
		ft_dpercentage(data);
	if (format[data->i] == 'x')
	{
		data->x = 1;
		ft_dhexa(data);
	}
	if (format[data->i] == 'X')
	{
		data->cap_x = 1;
		ft_dhexa(data);
	}
	ft_find_specifier_two(format, data);
}

static void	ft_save_int(const char *format, t_data *data)
{
	if (data->dot == 1)
	{
		data->str_len = ft_dadhoc_atoi(format, data);
		data->save_dot = 1;
	}
	if (data->dot == 0)
	{
		data->save = 1;
		data->xtra = ft_dadhoc_atoi(format, data);
	}
	data->i--;
	data->waste--;
	data->num = 0;
	data->dot = 0;
}

static void	ft_print_flag(const char *format, t_data *data)
{
	data->i++;
	data->waste++;
	while (format[data->i] != '\0')
	{
		if (ft_dspecifiers(format, data) == 0)
			break ;
		ft_dflags(format, data);
		if (data->num == 1)
			ft_save_int(format, data);
		data->i++;
		data->waste++;
	}
	if (data->star == '1')
		data->xtra = va_arg(data->copy, int);
	ft_find_specifier(format, data);
	ft_dreset_flags(data);
}

int	ft_dformat_str(const char *format, t_data *data)
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
			write(data->fd, &format[start], data->i - start);
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
