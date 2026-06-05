/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:51:53 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 15:00:46 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;
	size_t	j;

	slen = ft_strlen(src);
	i = 0;
	j = 0;
	if (dstsize == 0)
		return (slen);
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (slen);
}
