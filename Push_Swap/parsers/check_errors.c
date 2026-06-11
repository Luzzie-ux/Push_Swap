/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:36:26 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/11 19:50:51 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_errors(t_flags *flags, char **copy, int check)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		check_for_duple(copy, flags);
		check_for_letters(copy[i], flags);
		check_for_signs(copy[i], flags);
		i++;
	}
	if (check == 1 && flags->flag_name == ERROR)
		return (free_split(copy), 1);
	else if (flags->flag_name == ERROR)
		return (1);
	j = 0;
	while (copy[j])
	{
		(*flags).numbers[j] = ft_atoi(copy[j]);
		j++;
	}
	return (0);
}

void	check_for_duple(char **copy, t_flags *flags)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		if (ft_strcmp(copy[i], copy[i + 1]) == 0)
			flags->flag_name = ERROR;
		i++;
	}
}
void	check_for_letters(char *copy, t_flags *flags)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		if (copy[i] >= 'A' && copy[i] <= 'z')
			flags->flag_name = ERROR;
		i++;
	}
}
void	check_for_signs(char *copy, t_flags *flags)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		if (copy[i] >= '!' && copy[i] <= '*')
			flags->flag_name = ERROR;
		i++;
	}
}