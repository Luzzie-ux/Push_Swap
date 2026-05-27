/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:45:58 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/27 14:01:20 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	pa(t_list *stack_b, t_list *stack_a)
{
	if (ft_lstsize(stack_b) == 0)
		return ;
	else
		stack_a->content = stack_b->content;
}

void	pb(t_list *stack_b, t_list *stack_a)
{
	if (ft_lstsize(stack_a) == 0)
		return ;
	else
		stack_b->content = stack_a->content;
}
