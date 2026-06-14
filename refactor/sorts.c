/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:28:16 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 15:56:46 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "refactor.h"

void	sort_two(t_stack **a, int print)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->i > (*a)->next->i)
		sa(a, print);
}

void	sort_three(t_stack **a, int print)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)->i;
	second = (*a)->next->i;
	third = (*a)->next->next->i;
	if (first > second && second < third && first < third)
		sa(a, print);
	else if (first > second && second > third)
	{
		sa(a, print);
		rra(a, print);
	}
	else if (first > second && second < third && first > third)
		ra(a, print);
	else if (first < second && second > third && first < third)
	{
		sa(a, print);
		ra(a, print);
	}
	else if (first < second && second > third && first > third)
		rra(a, print);
}

static	void	move_min_to_top(t_stack **a, int print)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = get_min_node(*a);
	pos = get_node_pos(*a, min->i);
	size = get_stack_size(*a);
	if (pos <= size / 2)
	{
		while (*a != min)
			ra(a, print);
	}
	else
	{
		while (*a != min)
			rra(a, print);
	}
}

void	sort_five(t_stack **a, t_stack **b, int print)
{
	while (get_stack_size(*a) > 3)
	{
		move_min_to_top(a, print);
		pb(a, b, print);
	}
	sort_three(a, print);
	while (*b)
		pa(a, b, print);
}
