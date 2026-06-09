/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:51:37 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/09 18:51:48 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gets(char **args)
{
	char		*result;
	size_t		size;
	int			i;

	i = 0;
	if (!*args || !args)
		return (NULL);
	while (args[i])
	{
		size = ft_strlen(args[i + 1]);
		result = (char *)malloc(size + 1 * sizeof(char));
		if (!result)
			return (NULL);
		result = ft_memcpy(result, args[i + 1], size);
		result[size] = '\0';
		i++;
	}
	return (result);
}