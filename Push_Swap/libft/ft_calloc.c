/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:30:21 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/09 09:23:13 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*address;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	address = (void *)malloc(nmemb * size);
	if (address == NULL)
		return (NULL);
	ft_memset(address, 0, nmemb * size);
	return (address);
}
