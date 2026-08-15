/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:10:51 by diferrei          #+#    #+#             */
/*   Updated: 2026/05/21 10:41:49 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputnbr(int fd, int n)
{
	unsigned int	nb;
	int				len;
	int				i;
	char			x[12];

	i = 0;
	len = 0;
	if (n < 0)
	{
		len += write(fd, "-", 1);
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb == 0)
		return (write(fd, "0", 1));
	while (nb > 0)
	{
		x[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	len += i;
	while (--i >= 0)
		write(fd, &x[i], 1);
	return (len);
}

int	ft_fputnbr_unsigned(int fd, unsigned int nb)
{
	int		len;
	int		i;
	char	x[12];

	len = 0;
	i = 0;
	if (nb == 0)
		return (write(fd, "0", 1));
	while (nb > 0)
	{
		x[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	len += i;
	while (--i >= 0)
		write(fd, &x[i], 1);
	return (len);
}
