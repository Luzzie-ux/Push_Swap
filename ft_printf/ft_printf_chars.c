/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:12:01 by diferrei          #+#    #+#             */
/*   Updated: 2026/05/21 10:41:19 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(2, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	write(2, s, i);
	return (i);
}
