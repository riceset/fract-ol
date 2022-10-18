/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:25:25 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:53:16 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_fmt(va_list ap, const char *fmt, int *len, char *str)
{
	if (*fmt == '%')
		*len += ft_putchar('%');
	else if (*fmt == 'd' || *fmt == 'i')
		*len += ft_putnbr(va_arg(ap, int), "0123456789");
	else if (*fmt == 'u')
		*len += ft_putnbr(va_arg(ap, unsigned int), "0123456789");
	else if (*fmt == 'x')
		*len += ft_putnbr(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*fmt == 'X')
		*len += ft_putnbr(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*fmt == 'c')
		*len += ft_putchar(va_arg(ap, int));
	else if (*fmt == 'p')
	{
		*len += ft_putstr("0x");
		*len += ft_putaddr(va_arg(ap, unsigned long long), "0123456789abcdef");
	}
	else if (*fmt == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			*len += ft_putstr("(null)");
		else
			*len += ft_putstr(str);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;
	char	*str;

	va_start(ap, fmt);
	len = 0;
	str = NULL;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			put_fmt(ap, fmt, &len, str);
		}
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (len);
}
