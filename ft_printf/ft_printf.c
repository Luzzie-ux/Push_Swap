/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:18:08 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/26 11:59:33 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	phandler(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[i] == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if ((str[i] == 'd') || (str[i] == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_putnbr_un(va_arg(args, unsigned int)));
	else if (str[i] == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	else if (str[i] == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	else if (str[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	result = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			result += (phandler(++format, args));
		else
			result += (ft_putchar(*format));
		format++;
	}
	va_end(args);
	return (result);
}
