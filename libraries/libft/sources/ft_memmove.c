/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:26:24 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/23 13:45:34 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst < src)
		while (++i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	i = n + 1;
	if (dst > src)
		while (--i > 0)
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
	return (dst);
}
