/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:21:06 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/22 19:00:47 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s)
	{
		res = ft_calloc((ft_strlen(s) + 1), sizeof(char));
		if (res)
		{
			i = -1;
			while (s[++i])
				res[i] = f(i, s[i]);
			return (res);
		}
	}
	return (NULL);
}
