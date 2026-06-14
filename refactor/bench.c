

#include "refactor.h"

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