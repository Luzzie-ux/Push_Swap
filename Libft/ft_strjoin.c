/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:08:42 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 11:48:10 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	int		slnew;

	if (!s1 || !s2)
		return (NULL);
	slnew = ft_strlen(s1) + ft_strlen(s2);
	snew = malloc (slnew +1);
	if (!snew)
		return (NULL);
	ft_strlcpy(snew, s1, slnew + 1);
	ft_strlcat(snew, s2, slnew + 1);
	return (snew);
}
