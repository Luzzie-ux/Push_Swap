/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:59:00 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 18:36:44 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	else if (len > 0)
	{
		while (i <= len && big[i])
		{
			j = 0;
			if (big[i] == little[j] && i + j < len)
			{
				while (big[i + j] && little[j]
					&& big[i + j] == little[j] && i + j < len)
				{
					j++;
				}
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
			i++;
		}
	}
	return (NULL);
}
