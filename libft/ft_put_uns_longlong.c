/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_longlong.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:05:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:01:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_uns_longlong(unsigned long long n)
{
	char	res;

	if (n >= 10)
		ft_put_uns_longlong(n / 10);
	res = n % 10 + 48;
	write(1, &res, 1);
}
