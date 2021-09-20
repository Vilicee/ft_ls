/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:54:20 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 14:07:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_dhexadecimal(t_data *data, unsigned long long n)
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
		ft_dhexadecimal(data, n / base_n);
	res = n % base_n;
	data->ret++;
	write(data->fd, &base[res], 1);
}
