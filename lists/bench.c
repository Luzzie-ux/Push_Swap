/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:50:22 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 17:50:38 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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

t_bench	*get_bench(int *set_mode)
{
	static t_bench	bench;
	static int		mode = 0;

	if (set_mode)
		mode = *set_mode;
	if (mode == 0)
		return (NULL);
	return (&bench);
}

void	init_bench(double disorder, int mode, int bench)
{
	t_bench	*b;
	int		strategy_type;

	strategy_type = mode;
	b = get_bench(&bench);
	if (!b)
		return ;
	ft_bzero(b, sizeof(t_bench));
	b->disorder = disorder;
	if (strategy_type == SIMPLE)
		b->strategy = "Simple / O(n^2)";
	else if (strategy_type != MEDIUM && strategy_type != COMPLEX&& disorder < 0.2)
		b->strategy = "Adaptive / O(n^2)";
	else if (strategy_type == MEDIUM)
		b->strategy = "Medium / O(n√n)";
	else if (strategy_type != COMPLEX && disorder < 0.5)
		b->strategy = "Adaptive / O(n√n)";
	else if (strategy_type == COMPLEX)
		b->strategy = "Complex / O(n log n)";
	else
		b->strategy = "Adaptive / O(n log n)";
}
