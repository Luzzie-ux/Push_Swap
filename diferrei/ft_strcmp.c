/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:28:16 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 12:27:36 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static	void	move_min_to_top(t_stack **a, int print)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = get_min_node(*a);
	pos = get_node_pos(*a, min->i);
	size = get_stack_size(*a);
	if (pos <= size / 2)
	{
		while (*a != min)
			ra(a, print);
	}
	else
	{
		while (*a != min)
			rra(a, print);
	}
}

void	sort_five(t_stack **a, t_stack **b, int print)
{
	while (get_stack_size(*a) > 3)
	{
		move_min_to_top(a, print);
		pb(a, b, print);
	}
	sort_three(a, print);
	while (*b)
		pa(a, b, print);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	sort_two(t_stack **a, int print)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->i > (*a)->next->i)
		sa(a, print);
}
