/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:42:18 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/19 14:37:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_specifiers(const char *format, t_data *data)
{
	if (format[data->i] == 'c')
		return (0);
	if (format[data->i] == 's')
		return (0);
	if (format[data->i] == 'p')
		return (0);
	if (format[data->i] == 'd')
		return (0);
	if (format[data->i] == 'i')
		return (0);
	if (format[data->i] == 'o')
		return (0);
	if (format[data->i] == 'u')
		return (0);
	if (format[data->i] == 'x')
		return (0);
	if (format[data->i] == 'X')
		return (0);
	if (format[data->i] == 'f')
		return (0);
	if (format[data->i] == '%')
		return (0);
	return (-1);
}
