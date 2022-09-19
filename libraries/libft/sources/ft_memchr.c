/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:07:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/23 14:21:45 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	s--;
	i = -1;
	while (++i < n)
		if (*(unsigned char *)++s == (unsigned char)c)
			return ((unsigned char *)s);
	return (NULL);
}
