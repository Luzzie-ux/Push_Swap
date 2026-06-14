/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:04:33 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 15:01:45 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "refactor.h"

void	ra(t_stack **a, int print)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*a || !(*a)->next)
		return ;
	first_node = *a;
	last_node = *a;
	while (last_node->next)
		last_node = last_node->next;
	*a = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	count_op("ra");
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*b || !(*b)->next)
		return ;
	first_node = *b;
	last_node = *b;
	while (last_node->next)
		last_node = last_node->next;
	*b = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	count_op("rb");
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	count_op("rr");
	if (print)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, int print)
{
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = *a;
	while (last_node->next)
	{
		before_last_node = last_node;
		last_node = last_node->next;
	}
	before_last_node->next = NULL;
	last_node->next = *a;
	*a = last_node;
	count_op("rra");
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!*b || !(*b)->next)
		return ;
	last_node = *b;
	while (last_node ->next)
	{
		before_last_node = last_node;
		last_node = last_node->next;
	}
	before_last_node->next = NULL;
	last_node->next = *b;
	*b = last_node;
	count_op("rrb");
	if (print)
		write(1, "rrb\n", 4);
}
