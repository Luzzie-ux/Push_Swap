/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:49:07 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/08 13:29:21 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	if (ft_lstsize(*stack_a) < 2)
		return;
	head = (*stack_a);
	second = head->next;
	tail = second->next;

	(*stack_a) = second;
	second->prev = NULL;
	second->next = head;
	head->prev = second;
	head->next = tail;
	if (tail)
		tail->prev = head;
}

void	sb(t_list **stack_a)
{
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	if (ft_lstsize(*stack_a) < 2)
		return;
	head = (*stack_a);
	second = head->next;
	tail = second->next;

	(*stack_a) = second;
	second->prev = NULL;
	second->next = head;
	head->prev = second;
	head->next = tail;
	if (tail)
		tail->prev = head;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
