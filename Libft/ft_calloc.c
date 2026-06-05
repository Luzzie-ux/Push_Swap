/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:30:21 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 19:33:03 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*adress;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	adress = (void *)malloc(nmemb * size);
	if (adress == NULL)
		return (NULL);
	ft_memset(adress, 0, nmemb * size);
	return (adress);
}
