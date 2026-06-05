/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:27:56 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 14:48:54 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev(char *s)
{
	char	temp;
	int		start;
	int		end;

	end = ft_strlen(s) - 1;
	start = 0;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
	return (s);
}

static char	*helper(int n, char *ptr)
{
	int	digit;

	while (n != 0)
	{
		digit = n % 10;
		if (n < 0)
			digit = digit * -1;
		*ptr++ = digit + '0';
		n = n / 10;
	}
	return (ptr);
}

static int	count(int n)
{
	int	digit;

	if (n == 0)
		return (1);
	digit = 0;
	if (n < 0)
		digit = 1;
	while (n != 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*buffer;
	char	*ptr;

	sign = 1;
	buffer = (char *)malloc(sizeof(char) * count(n) + 1);
	if (!buffer)
		return (NULL);
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	else if (n < 0)
	{
		sign = -1;
	}
	ptr = helper(n, buffer);
	if (sign == -1)
		*ptr++ = '-';
	*ptr = 0;
	rev(buffer);
	return (buffer);
}
