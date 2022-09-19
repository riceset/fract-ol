/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:09:47 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/24 14:52:16 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (substr[0] == '\0')
		return ((char *)str);
	i = -1;
	while (str[++i])
	{
		k = i - 1;
		j = -1;
		if (str[i] == substr[0])
			while (str[++k] == substr[++j] && substr[j])
				if (j + 1 == ft_strlen(substr) && k < len)
					return ((char *)(str + i));
	}
	return (NULL);
}
