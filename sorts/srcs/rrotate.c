/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:50:57 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/27 16:53:33 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	rra(t_list **stack_a)
{
	t_list	*tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tail = ft_lstlast(*stack_a);
	tail->prev->next = NULL;
	tail->next = *stack_a;
	tail->next->prev = tail;
	(*stack_a) = tail;
}

void	rrb(t_list **stack_b)
{
	t_list	*tail;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tail = ft_lstlast(*stack_b);
	tail->prev->next = NULL;
	tail->next = *stack_b;
	tail->next->prev = tail;
	(*stack_b) = tail;
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rra(&stack_a);
	rrb(&stack_b);
}
