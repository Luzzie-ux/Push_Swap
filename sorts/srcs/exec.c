/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:05:23 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/01 20:00:00 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

/*
void	execute(int strat, t_list *stack)
{
	int	i;
	int	j;

	if (strat == 0)
		simple(stack);
	else if (strat == 1)
		medium(stack);
	else if (strat == 2)
		complex(stack);
	else if (strat == 3)
		adaptative(stack);
	else
		return ;
} */
/*
int	compute_disorder(t_list *a)
{
	int	total_pairs;
	int	mistakes;
	int	i;
	int	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i <  ft_lstsize(a) - 1)
	{
		j = i + 1;
		while (j < ft_lstsize(a) - 1)
		{
			total_pairs += 1;
			if (a->content > a->next->content)
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

int	benchmark(int bench, t_list *stack)
{
	int	i = 0;
	if (bench != 1)
		return (0);
	i = compute_disorder(stack);
	return (i);
}
*/