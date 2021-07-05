/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:55:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/19 16:22:25 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexa_len(t_data *data, unsigned long long n)
{
	int					count;
	unsigned long long	base;

	count = 0;
	base = data->base;
	while (n >= base)
	{
		n = n / base;
		count++;
	}
	count++;
	return (count);
}
