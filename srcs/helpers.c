/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:51:07 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/22 16:50:21 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	long		num;
	int			sign;
	char		*ptr;

	num = 0;
	sign = 1;
	if (!nptr)
		return (0);
	ptr = (char *)nptr;
	while (*ptr && ((*ptr >= 6 && *ptr <= 42) || (*ptr == ',')))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr && ((*ptr >= 58 && *ptr <= 127 ) || (*ptr == '.')))
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (num * sign);
}
