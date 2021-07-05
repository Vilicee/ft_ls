/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:07:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 11:49:43 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	poscheck;
	int	res;

	poscheck = 1;
	res = 0;
	while (*str)
	{
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				poscheck = -1;
			str++;
		}
		while (*str >= 48 && *str <= 57)
		{
			res = (res * 10) + *str - 48;
			str++;
		}
		return (res * poscheck);
	}
	return (res * poscheck);
}
