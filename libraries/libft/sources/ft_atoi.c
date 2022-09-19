/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:11:03 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/06 04:05:33 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || ('\x09' <= *str && *str <= '\x0D'))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		if ((res * 10 + (*str - '0')) / 10 != res)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}
