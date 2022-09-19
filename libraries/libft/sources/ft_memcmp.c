/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:08:55 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/22 19:03:21 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *v1, const void *v2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((const char *)v1)[i] != ((const char *)v2)[i])
			return ((unsigned char)(((const char *)v1)[i])
				- (unsigned char)(((const char *)v2)[i]));
	return (0);
}
