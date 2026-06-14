/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:52:25 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 18:04:58 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b, t_flags *mode)
{
	int		print;

	if (is_sorted(*a))
		return ;
	print = 1;
	if (mode->disorder < 0.2)
		sort_simple(a, b, print);
	else if (mode->disorder < 0.5)
		sort_medium(a, b, print);
	else
		sort_complex(a, b, print);
}
