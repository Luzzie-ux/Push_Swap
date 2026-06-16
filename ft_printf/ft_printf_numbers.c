/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:10:51 by diferrei          #+#    #+#             */
/*   Updated: 2026/05/21 10:41:49 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				len;
	int				i;
	char			x[12];

	i = 0;
	len = 0;
	if (n < 0)
	{
		len += write(2, "-", 1);
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb == 0)
		return (write(2, "0", 1));
	while (nb > 0)
	{
		x[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	len += i;
	while (--i >= 0)
		write(2, &x[i], 1);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int		len;
	int		i;
	char	x[12];

	len = 0;
	i = 0;
	if (nb == 0)
		return (write(2, "0", 1));
	while (nb > 0)
	{
		x[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	len += i;
	while (--i >= 0)
		write(2, &x[i], 1);
	return (len);
}
