/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:53:20 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/13 19:07:13 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_errors(char **num)
{
	int		i;
	long	val;

	i = 0;
	val = 0;
	if (check_for_duple(num))
		return (ft_putstr_fd("Found duple\n", 2), 1);
	while (num[i])
	{
		val = ft_atol(num[i]);
		if (val > 2147483647 || val < -2147483648)
			return (ft_putstr_fd("Overflow\n", 2), 1);
		else if(check_for_letters(num[i]))
			return (ft_putstr_fd("Found letter\n", 2), 1);
		else if(check_for_signs(num[i]))
			return (ft_putstr_fd("Found signs\n", 2), 1);
		i++;
	}
	if (check_for_duple2(num))
		return (ft_putstr_fd("Found duple\n", 2), 1);
	return (0);
}

int	check_for_duple(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = i + 1;
		while (copy[j])
		{
			if (ft_strcmp(copy[i], copy[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_letters(char *copy)
{
	int	i;

	i = 0;
	if (copy[i] == '\0')
		return (1);
	if (copy[i] == '+' || copy[i] == '-')
		i++;
	while (copy[i])
	{
		if (!(copy[i] >= '0' && copy[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_for_signs(char *copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		if ((copy[i + 1] == '\0' || copy[i + 1] == '+')
			&& (copy[i] == '-' || copy[i] == '+'))
			return (1);
		else if ((copy[i] >= '!' && copy[i] <= '*') || copy[i] == ',')
			return (1);
		else if (copy[i] == '.' || (copy[i] >= ':' && copy[i] <= '@'))
			return (1);
		else if (copy[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	check_for_duple2(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = i + 1;
		while (copy[j])
		{
			if (ft_atoi(copy[i]) == ft_atoi(copy[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}