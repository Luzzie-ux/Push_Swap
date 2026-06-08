/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:04:29 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/08 18:39:09 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long nbr)
{
	int	result;

	result = 0;
	if (nbr < 0)
	{
		result += ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		result += ft_putnbr(nbr / 10);
		result += ft_putchar((nbr % 10) + '0');
	}
	else
		result += ft_putchar((nbr % 10) + '0');
	return (result);
}

int	ft_putnbr_un(unsigned int nbr)
{
	int	result;

	result = 0;
	if (nbr >= 10)
	{
		result += ft_putnbr_un(nbr / 10);
		result += ft_putchar((nbr % 10) + '0');
	}
	else
		result += ft_putchar((nbr % 10) + '0');
	return (result);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_puthex(unsigned int nbr, char format)
{
	int		result;
	long	n;
	char	*hex;

	result = 0;
	n = nbr;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 15)
		result += ft_puthex(n / 16, format);
	result += ft_putchar(hex[n % 16]);
	return (result);
}
