/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:02:05 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/12 12:29:45 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf.h"

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

void	init_bench(double disorder, int mode)
{
	t_bench	*b;
	int		strategy_type;

	strategy_type = mode;
	if (mode == 2 || mode == 3 || mode == 4)
		mode = 1;
	b = get_bench(&mode);
	if (!b)
		return ;
	ft_bzero(b, sizeof(t_bench));
	b->disorder = disorder;
	if (strategy_type == 2)
		b->strategy = "Simple / O(n^2)";
	else if (strategy_type != 3 && strategy_type != 4 && disorder < 0.2)
		b->strategy = "Adaptive / O(n^2)";
	else if (strategy_type == 3)
		b->strategy = "Medium / O(n√n)";
	else if (strategy_type != 4 && disorder < 0.5)
		b->strategy = "Adaptive / O(n√n)";
	else if (strategy_type == 4)
		b->strategy = "Complex / O(n log n)";
	else
		b->strategy = "Adaptive / O(n log n)";
}

static void	count_op_sp_r(t_bench *b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		b->sa++;
	else if (ft_strcmp(op, "sb") == 0)
		b->sb++;
	else if (ft_strcmp(op, "ss") == 0)
		b->ss++;
	else if (ft_strcmp(op, "pa") == 0)
		b->pa++;
	else if (ft_strcmp(op, "pb") == 0)
		b->pb++;
	else if (ft_strcmp(op, "ra") == 0)
		b->ra++;
	else if (ft_strcmp(op, "rb") == 0)
		b->rb++;
	else if (ft_strcmp(op, "rr") == 0)
		b->rr++;
	else if (ft_strcmp(op, "rra") == 0)
		b->rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		b->rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		b->rrr++;
}

void	count_op(char *op)
{
	t_bench	*b;

	b = get_bench(NULL);
	if (!b)
		return ;
	b->total_operations++;
	count_op_sp_r(b, op);
}
