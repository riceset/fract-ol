/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:01:42 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/22 19:04:16 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && f_dst_s == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (f_dst_s == 0)
		return (src_len);
	if (dst_len < f_dst_s)
	{
		i = -1;
		while (src[++i] && i + 1 < f_dst_s - dst_len)
			dst[dst_len + i] = src[i];
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + f_dst_s);
}
