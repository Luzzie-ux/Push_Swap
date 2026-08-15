/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:12:01 by diferrei          #+#    #+#             */
/*   Updated: 2026/05/21 10:41:19 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_fputstr(int fd, char *s)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	write(fd, s, i);
	return (i);
}
