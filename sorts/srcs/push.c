/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:45:58 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/26 18:33:45 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.h"

void	pa(t_list *stack_b, t_list *stack_a)
{
	if (stack_b->content == NULL)
		return ;
	else
		stack_a->content = stack_b->content;
}

void	pb(t_list *stack_b, t_list *stack_a)
{
	if (stack_a->content == NULL)
		return ;
	else
		stack_b->content = stack_a->content;
}
