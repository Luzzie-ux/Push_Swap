/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:10:09 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 18:05:06 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	get_pivot(t_stack *a)
{
	int	min;
	int	max;

	min = get_min_node(a)->i;
	max = get_max_node(a)->i;
	return ((min + (max - min) / 2));
}

static int	find_push_pos(t_stack *a, int val)
{
	t_stack	*curr;
	int		pos;

	curr = a;
	pos = 0;
	if (val < get_min_node(a)->i || val > get_max_node(a)->i)
		return (get_node_pos(a, get_min_node(a)->i));
	while (curr && curr->next)
	{
		if (val > curr->i && val < curr->next->i)
			return (pos + 1);
		pos++;
		curr = curr->next;
	}
	return (0);
}

static void	insert_back_to_a(t_stack **a, t_stack **b, int print)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = find_push_pos(*a, (*b)->i);
		size = get_stack_size(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a, print);
		}
		else
		{
			while (pos++ < size)
				rra(a, print);
		}
		pa(a, b, print);
	}
}

void	sort_simple(t_stack **a, t_stack **b, int print)
{
	int	pivot;
	int	size;

	if (is_sorted(*a))
		return ;
	else if (get_stack_size(*a) == 2)
		sort_two(a, print);
	while (get_stack_size(*a) > 3)
	{
		pivot = get_pivot(*a);
		size = get_stack_size(*a);
		while (size-- > 0 && get_stack_size(*a) > 3)
		{
			if ((*a)->i <= pivot)
				pb(a, b, print);
			else
				ra(a, print);
		}
	}
	sort_three(a, print);
	insert_back_to_a(a, b, print);
	while (!is_sorted(*a))
		rra(a, print);
}
