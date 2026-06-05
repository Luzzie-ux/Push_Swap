/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:28:24 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 19:35:12 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && iset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && iset(s1[end], set))
		end--;
	result = (char *)malloc(end - start + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 2);
	return (result);
}
