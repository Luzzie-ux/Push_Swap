/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:18:08 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/12 12:29:56 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	max_bits;

	max_index = get_stack_size(stack) - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	is_size_five_or_less(t_stack **a, t_stack **b, int print)
{
	if (get_stack_size(*a) == 2 && !is_sorted(*a))
		return (sort_two(a, print));
	else if (get_stack_size(*a) <= 3 && !is_sorted(*a))
		return (sort_three(a, print));
	else if (get_stack_size(*a) <= 5 && !is_sorted(*a))
		return (sort_five(a, b, print));
}

void	sort_complex(t_stack **a, t_stack **b, int print)
{
	int	i;
	int	j;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(*a);
	is_size_five_or_less(a, b, print);
	while (i < max_bits && !is_sorted(*a))
	{
		j = get_stack_size(*a);
		while (j-- > 0)
		{
			if ((((*a)->i >> i) & 1) == 0)
				pb(a, b, print);
			else
				ra(a, print);
		}
		while (*b)
			pa(a, b, print);
		i++;
	}
}
