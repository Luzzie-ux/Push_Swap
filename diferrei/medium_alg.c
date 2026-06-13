/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:02:37 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/09 16:45:44 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	range_size(int size)
{
	if (size <= 20)
		return (4);
	if (size <= 100)
		return (size / 6);
	return (size / 14);
}

static void	move_max_to_a(t_stack **a, t_stack **b, int print)
{
	t_stack	*max;
	int		pos;
	int		size;

	if (!*b)
		return ;
	max = get_max_node(*b);
	pos = get_node_pos(*b, max->i);
	size = get_stack_size(*b);
	if (pos <= size / 2)
	{
		while (*b != max)
			rb(b, print);
	}
	else
	{
		while (*b != max)
			rrb(b, print);
	}
	pa(a, b, print);
}

static void	push_chunks(t_stack **a, t_stack **b, int range, int print)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->i <= i)
		{
			pb(a, b, print);
			rb(b, print);
			i++;
		}
		else if ((*a)->i <= i + range)
		{
			pb(a, b, print);
			i++;
		}
		else
			ra(a, print);
	}
}

void	sort_medium(t_stack **a, t_stack **b, int print)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = get_stack_size(*a);
	if (size == 2)
		return (sort_two(a, print));
	if (size <= 3)
		return (sort_three(a, print));
	if (size <= 5)
		return (sort_five(a, b, print));
	push_chunks(a, b, range_size(size), print);
	while (*b)
		move_max_to_a(a, b, print);
}
