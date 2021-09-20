/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:54:20 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:21:33 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_hexadecimal(t_printf *data, unsigned long long n)
{
	char				*base;
	int					res;
	unsigned long long	base_n;

	base_n = data->base;
	if (data->x == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= base_n)
		ft_hexadecimal(data, n / base_n);
	res = n % base_n;
	data->ret++;
	write(1, &base[res], 1);
}
