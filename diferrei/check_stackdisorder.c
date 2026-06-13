/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stackdisorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:31:43 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 12:26:52 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->i > stack->next->i)
			return (0);
		stack = stack->next;
	}
	return (1);
}

double	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*check;

	mistakes = 0;
	total_pairs = 0;
	current = a;
	if (!a || !a->next)
		return (0.0);
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->i > check->i)
				mistakes++;
			total_pairs++;
			check = check->next;
		}
		current = current->next;
	}
	return ((double)mistakes / total_pairs);
}
