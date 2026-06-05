/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:51:11 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/21 12:20:51 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	unsigned const char	*ps;

	pd = (unsigned char *)dest;
	ps = (unsigned const char *)src;
	if (dest == src || n == 0)
	{
		return (dest);
	}
	if (dest < src)
	{
		while (n--)
			*pd++ = *ps++;
	}
	else
	{
		pd = pd + n - 1;
		ps = ps + n - 1;
		while (n--)
			*pd-- = *ps--;
	}
	return (dest);
}
