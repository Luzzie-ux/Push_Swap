/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:51:21 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/29 16:45:46 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	if (size <= dlen)
		return (size + slen);
	if (size > 0)
	{
		j = 0;
		while (src[j] != '\0' && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (dlen + slen);
}
