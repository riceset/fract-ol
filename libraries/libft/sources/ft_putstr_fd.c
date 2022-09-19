/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:27:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/22 19:01:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		while (len > INT_MAX)
		{
			write(fd, s, INT_MAX);
			s += INT_MAX;
			len -= INT_MAX;
		}
		write(fd, s, len);
	}
}
