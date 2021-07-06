/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:57:35 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/06 15:48:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_uns_itoa(unsigned long long n)
{
	char	*string;
	int		i;

	i = ft_uns_longlong_len(n);
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	ft_bzero(string, i);
	if (n < 0)
	{
		string[0] = '-';
		n = n * -1;
	}
	string[i] = '\0';
	while (n >= 0 && i > 0 && string[i - 1] != '-')
	{
		string[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (string);
}
