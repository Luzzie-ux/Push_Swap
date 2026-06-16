/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:34:49 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 17:54:22 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sa(t_stack **a, int print)
{
	int	tmp_val;
	int	tmp_index;

	if (!*a || !(*a)->next)
		return ;
	tmp_val = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp_val;
	tmp_index = (*a)->i;
	(*a)->i = (*a)->next->i;
	(*a)->next->i = tmp_index;
	count_op("sa");
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	int	tmp_val;
	int	tmp_index;

	if (!*b || !(*b)->next)
		return ;
	tmp_val = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp_val;
	tmp_index = (*b)->i;
	(*b)->i = (*b)->next->i;
	(*b)->next->i = tmp_index;
	count_op("sb");
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	count_op("ss");
	if (print)
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	count_op("pa");
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	count_op("pb");
	if (print)
		write(1, "pb\n", 3);
}
