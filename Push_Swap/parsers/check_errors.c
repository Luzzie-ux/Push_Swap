/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:36:26 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:18 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int check_for_duple();
static int check_for_letters();
static int check_for_signs();

int	check_errors(t_flags *flags, char **copy, int check)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] >= 'A' && copy[i][j] <= 'z')
				flags->flag_name = ERROR;
			j++;
		}
		i++;
	}
	if (flags->flag_name == ERROR)
		return (1);
	else if (check == 1 && flags->flag_name == ERROR)
		return (free_split(copy), 1);
	while (copy[j])
	{
		(*flags).numbers[j] = ft_atoi(copy[j]);
		j++;
	}
	return (0);
}

static int check_for_duple()
{
	;
}
static int check_for_letters()
{
	;
}
static int check_for_signs()
{
	;
}