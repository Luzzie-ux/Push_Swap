/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:45:58 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/28 11:40:48 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	(*stack_b) = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node->next = (*stack_a);
	node->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = node;
	(*stack_a) = node;
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	(*stack_a) = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node->next = (*stack_b);
	node->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = node;
	(*stack_b) = node;
}
