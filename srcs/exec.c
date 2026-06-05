/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:05:23 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/05 09:38:38 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

t_list	*execute(int strat, int bench, float d, t_list *stack)
{

	(void)bench;
	(void)d;
	if (strat == 0)
		simple(stack);
	/* else if (strat == 1)
		count = medium(stack);
	else if (strat == 2)
		count = complex(stack);
	else if (strat == 3)
		count = adaptative(stack);
	else if (bench == 1)
		return (benchmark(strat, d, count, stack)); */
	return (stack);
}

float	compute_disorder(t_list *a)
{
	float	total_pairs;
	float	mistakes;
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;
	int		j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	tmp1 = a;
	while (i <  ft_lstsize(a))
	{
		j = i + 1;
		tmp2 = tmp1->next;
		while (j < ft_lstsize(a))
		{
			total_pairs += 1;
			if (tmp1->content > tmp2->content)
				mistakes += 1;
			tmp2 = tmp2->next;
			j++;
		}
		tmp1 = tmp1->next;
		i++;
	}
	return (mistakes / total_pairs);
}
/* 
int	benchmark(int strat, int d, int count, t_list *stack)
{
	int total_ops;
	char *disorder; 
	
	disorder = itoa((d * 100) / 1);
	total_ops = count;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putstr_fd(dis, 2);
	ft_putchar_fd('%',2);
	if (strat == 0)
		ft_putstr("[bench] strategy: simple / O(nˆ2)", 2);
	else if (strat == 1)
		ft_putstr("[bench] strategy: medium / O(nVn)", 2);
	else if (strat == 2)
		ft_putstr("[bench] strategy: complex / O(n log n)", 2);
	else if (strat == 3)
		ft_putstr("[bench] strategy: adaptive / O(1)", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putstr_fd(total_ops, 2);
}
 */