/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:04:26 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:24:06 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_skip_flags(const char *format, t_printf *data)
{
	int	error;

	error = 0;
	while (ft_specifiers(format, data) == -1 && format[data->i] != '\0')
	{
		if (ft_flags(format, data) == -1)
			return (-1);
		data->i++;
	}
	if (format[data->i] == '\0')
		error = -1;
	return (error);
}

static int	ft_possible_flag(const char *format, t_printf *data)
{
	int	ret;

	ret = 0;
	data->i++;
	if (format[data->i] == '\0')
		return (-1);
	if (format[data->i] == '%')
		return (0);
	if (ft_specifiers(format, data) == -1)
		ret = ft_skip_flags(format, data);
	return (ret);
}

void	ft_validate_flags(const char *format, t_printf *data)
{
	int	i;

	i = 0;
	while (format[data->i] != '\0')
	{
		if (format[data->i] == '%')
		{
			data->flag[i] = ft_possible_flag(format, data);
			i++;
		}
		data->i++;
	}
}
