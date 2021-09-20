/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:40:02 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:23:40 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_string(t_printf *data, char *temp)
{
	if (data->just_dot == 1)
		data->len = 0;
	else
		write(1, temp, data->len);
}

static void	ft_str_space(t_printf *data, char *temp)
{
	if (data->minus == 1)
		ft_print_string(data, temp);
	while (data->xtra > data->len)
	{
		if (data->zero == '0')
			write(1, " ", 1);
		else
			write(1, "0", 1);
		data->xtra--;
		data->ret++;
	}
	if (data->minus == 0)
		ft_print_string(data, temp);
	data->minus = 0;
}

void	ft_string(t_printf *data)
{
	char	*temp;

	if (data->zero == '1' && data->minus == 1)
		data->zero = '0';
	temp = ft_strdup(va_arg(data->copy, char *));
	if (!temp)
		temp = ft_strdup("(null)");
	data->len = ft_strlen(temp);
	if (data->str_len < data->len && data->save_dot == 1)
		data->len = data->str_len;
	if (data->just_dot == 1)
		data->len = 0;
	if (data->save == 1 || data->star == '1')
		ft_str_space(data, temp);
	else
		ft_print_string(data, temp);
	data->waste++;
	data->ret = data->ret + data->len;
	free(temp);
}
