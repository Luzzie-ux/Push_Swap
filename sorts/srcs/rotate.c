/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:50:05 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/28 12:10:14 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	ra(t_list **stack_a)
{
	t_list	*tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tail = ft_lstlast(*stack_a);
	tail->prev->next = NULL;
	(*stack_a)->prev = tail;
	tail->next = *stack_a;
	tail->prev = NULL;
	(*stack_a) = tail;
}

void	rb(t_list **stack_b)
{
	t_list	*tail;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tail = ft_lstlast(*stack_b);
	tail->prev->next = NULL;
	(*stack_b)->prev = tail;
	tail->next = *stack_b;
	tail->prev = NULL;
	(*stack_b) = tail;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
