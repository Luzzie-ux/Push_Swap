/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:43:08 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/25 19:13:56 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	char	*ptr;

	num = 0;
	sign = 1;
	if (!nptr)
		return (0);
	ptr = (char *)nptr;
	while (*ptr && !(*ptr >= '0' && *ptr <= '9') && *ptr != '-' && *ptr != '+')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr && !(*ptr >= '0' && *ptr <= '9'))
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (num * sign);
}

int	isnum(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	loop(int i, int argc, char **argv)
{
	int	bench;
	int	strat;
	int	skip;
	int	f;

	bench = 0;
	strat = 3;
	skip = 0;
	while (i < (argc - 1) && (argv[i][0] == '-' && argv[i][1] == '-'))
	{
		f = flags(argv[i]);
		if (f == -1)
			return (-1);
		if (f == 10)
			bench = 1;
		else
			strat = f;
		skip++;
		i++;
	}
	return (skip * 100 + strat * 10 + bench);
}
