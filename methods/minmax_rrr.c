/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_minmax_rrr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:09:55 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 17:54:15 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	count_op("rrr");
	if (print)
		write(1, "rrr\n", 4);
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->i < min_node->i)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*get_max_node(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->i > max_node->i)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	set_index(t_stack *a)
{
	t_stack	*min;
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = a;
	while (tmp)
	{
		tmp->i = -1;
		tmp = tmp->next;
	}
	while (index < get_stack_size(a))
	{
		min = NULL;
		tmp = a;
		while (tmp)
		{
			if (tmp->i == -1 && (!min || tmp->value < min->value))
				min = tmp;
			tmp = tmp->next;
		}
		if (min)
			min->i = index++;
	}
}

int	get_node_pos(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->i == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (pos);
}
