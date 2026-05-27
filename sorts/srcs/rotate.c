/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:50:05 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/27 16:55:17 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	ra(t_list **stack_a)
{
	t_list *tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tail = ft_lstlast(*stack_a);
	tail->next = *stack_a;
}

void	rb(t_list *stack_b)
{
	t_list *tail;
	
	tail = ft_lstlast(stack_b);
	tail->next = stack_b;
	stack_b->next = NULL;
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(&stack_a);
	rb(stack_b);
}
