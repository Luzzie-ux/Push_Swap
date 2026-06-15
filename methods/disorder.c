/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:45:25 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/15 14:26:54 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	*compute_disorder(t_flags *array)
{
	int		i;
	int		j;
	int		mistakes;
	int		total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < array->nsize)
	{
		j = i + 1;
		while (j < array->nsize)
		{
			total_pairs += 1;
			if (array->numbers[i] > array->numbers[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (array->disorder = ((double)mistakes / total_pairs), NULL);
}
