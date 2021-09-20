/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:40:02 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 12:13:21 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_print_string(t_data *data, char *temp)
{
	if (data->just_dot == 1)
		data->len = 0;
	else
		write(data->fd, temp, data->len);
}

static void	ft_str_space(t_data *data, char *temp)
{
	if (data->minus == 1)
		ft_print_string(data, temp);
	while (data->xtra > data->len)
	{
		if (data->zero == '0')
			write(data->fd, " ", 1);
		else
			write(data->fd, "0", 1);
		data->xtra--;
		data->ret++;
	}
	if (data->minus == 0)
		ft_print_string(data, temp);
	data->minus = 0;
}

void	ft_dstring(t_data *data)
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
	ft_memdel((void *)&temp);
}
