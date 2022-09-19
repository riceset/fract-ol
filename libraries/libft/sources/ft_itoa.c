/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:19:45 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/25 22:28:49 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	res;

	res = 0;
	if (n < 0)
		res++;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static char	*helper(int n, int digits, char *res)
{
	int	or_n;

	or_n = n;
	if (n == 0)
		res[digits - 1] = 0 + '0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == INT_MIN)
			n++;
		n *= -1;
	}
	while (n)
	{
		res[digits - 1] = n % 10 + '0';
		n /= 10;
		digits--;
	}
	if (or_n == INT_MIN)
		res[10] = '8';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		digits;

	digits = count_digits(n);
	res = ft_calloc((digits + 1), sizeof(char));
	if (res)
	{
		helper(n, digits, res);
		return (res);
	}
	return (NULL);
}
