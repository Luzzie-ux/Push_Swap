/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:52:25 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 12:26:19 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b, int mode)
{
	double	disorder;
	int		print;

	if (is_sorted(*a))
		return ;
	print = 1;
	disorder = compute_disorder(*a);
	if (mode == 2 || (mode != 3 && mode != 4 && disorder < 0.2))
		sort_simple(a, b, print);
	else if (mode == 3 || (mode != 4 && disorder < 0.5))
		sort_medium(a, b, print);
	else
		sort_complex(a, b, print);
}
