/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:12:38 by diferrei          #+#    #+#             */
/*   Updated: 2026/05/21 10:42:20 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputnbr_hex(int fd, unsigned long nb, char c)
{
	int		len;
	int		i;
	char	*base;
	char	x[17];

	if (c != 'X' && c != 'x')
		return (0);
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	len = 0;
	if (nb == 0)
		return (write(fd, "0", 1));
	while (nb > 0)
	{
		x[i++] = base[nb % 16];
		nb /= 16;
	}
	len += i;
	while (--i >= 0)
		write(fd, &x[i], 1);
	return (len);
}

int	ft_fputptr(int fd, void *ptr)
{
	int				len;
	unsigned long	adress;

	adress = (unsigned long)ptr;
	len = 2;
	if (adress == 0)
		return (write(2, "(nil)", 5));
	write(1, "0x", 2);
	len += ft_fputnbr_hex(fd, adress, 'x');
	return (len);
}
