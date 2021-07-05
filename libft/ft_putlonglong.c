/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:07:01 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:02:05 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putlonglong(long long int n)
{
	char	res;

	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putlonglong(n * 0.1);
	res = n % 10 + 48;
	write(1, &res, 1);
}
