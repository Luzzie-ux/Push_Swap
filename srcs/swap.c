/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:49:07 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/28 12:12:22 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	sa(t_list *stack_a)
{
	long		temp;

	if (ft_lstsize(stack_a) < 2)
		return ;
	else
	{
		temp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = temp;
	}
}

void	sb(t_list *stack_b)
{
	int		temp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	else
	{
		temp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = temp;
	}
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
