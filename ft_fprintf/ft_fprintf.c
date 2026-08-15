/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:52:08 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 21:17:34 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_fconversion(int fd, va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_fputchar(fd, va_arg(args, int));
	else if (format == '%')
		len += ft_fputchar(fd, '%');
	else if (format == 's')
		len += ft_fputstr(fd, va_arg(args, char *));
	else if (format == 'p')
		len += ft_fputptr(fd, va_arg(args, void *));
	else if (format == 'x' || format == 'X')
		len += ft_fputnbr_hex(fd, (unsigned int)va_arg(args, unsigned long), format);
	else if (format == 'd' || format == 'i')
		len += ft_fputnbr(fd, va_arg(args, int));
	else if (format == 'u')
		len += ft_fputnbr_unsigned(fd, va_arg(args, unsigned int));
	return (len);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int		i;
	int		total_len;
	va_list	args;

	i = 0;
	total_len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			total_len += ft_fputchar(fd, format[i]);
		else if (format[i] == '%')
		{
			total_len += ft_fconversion(fd, args, format[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}
