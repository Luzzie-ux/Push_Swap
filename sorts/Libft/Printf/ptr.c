/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 18:38:07 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/08 18:38:28 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long n)
{
	int		result;

	result = 0;
	if (n > 15)
		result += ft_puthex_ptr(n / 16);
	result += ft_putchar("0123456789abcdef"[n % 16]);
	return (result);
}

int	ft_putptr(void *ptr)
{
	unsigned long		n;
	int					result;

	result = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	n = (unsigned long)ptr;
	result += ft_putstr("0x");
	result += ft_puthex_ptr(n);
	return (result);
}
