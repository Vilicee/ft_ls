/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhexa_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:55:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 14:46:18 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

int	ft_dhexa_len(t_data *data, unsigned long long n)
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
