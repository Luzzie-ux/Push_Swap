/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:44:18 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/12 12:30:36 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf.h"

static void	print_disorder_to_bench(t_bench *b)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(b->disorder * 100);
	dec_part = (int)((b->disorder * 100 - int_part) * 100);
	if (dec_part < 0)
		dec_part = -dec_part;
	write(2, "[bench] disorder:  ", 19);
	if (dec_part < 10)
		ft_printf("%d.0%d%%\n", int_part, dec_part);
	else
		ft_printf("%d.%d%%\n", int_part, dec_part);
}

void	print_bench(void)
{
	t_bench	*b;

	b = get_bench(NULL);
	if (!b)
		return ;
	print_disorder_to_bench(b);
	ft_printf("[bench] strategy:  %s\n", b->strategy);
	ft_printf("[bench] total_ops: %d\n", b->total_operations);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra: %d  rrb: %d  rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}
