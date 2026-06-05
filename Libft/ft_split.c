/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:46:57 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/29 09:47:38 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char delimiter)
{
	size_t	counter;
	int		i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i] != '\0')
		{
			counter++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
	}
	return (counter);
}

static char	*alloc(const char *s, int start, int end, char **string)
{
	int		i;
	char	*sword;

	i = 0;
	sword = malloc((end - start + 1) * sizeof(char));
	if (!sword)
	{
		while (string[i])
			free(string[i++]);
		free(string);
		return (NULL);
	}
	while (end > start)
		sword[i++] = s[start++];
	sword[i] = 0;
	return (sword);
}

static char	**ft(const char *s, char c, char **result)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (s[i] || start >= 0)
	{
		if (s[i] && s[i] != c && start < 0)
			start = i;
		else if ((!s[i] || s[i] == c) && start >= 0)
		{
			result[j] = alloc(s, start, i, result);
			if (!result[j])
				return (NULL);
			start = -1;
			j++;
		}
		i += (s[i] != '\0');
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (ft(s, c, result));
}
