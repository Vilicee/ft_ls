/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:17:49 by wvaara            #+#    #+#             */
/*   Updated: 2021/03/04 12:53:13 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		ii;
	char	temp;

	i = 0;
	ii = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	i--;
	while (ii < i)
	{
		temp = str[i];
		str[i] = str[ii];
		str[ii] = temp;
		i--;
		ii++;
	}
	return (str);
}
