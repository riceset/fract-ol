/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:11:53 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/22 19:00:15 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	js;

	if (s1 && s2)
	{
		js = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
		j = malloc(js);
		if (j)
		{
			ft_strlcpy(j, s1, ft_strlen(s1) + 1);
			ft_strlcat(j, s2, js);
			return (j);
		}
	}
	return (NULL);
}
