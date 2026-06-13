/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:34:04 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 12:28:10 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

t_stack	*parse_input(char **argv)
{
	t_stack	*a;
	t_stack	*new_node;
	long	val;
	int		i;

	a = NULL;
	i = -1;
	while (argv[++i])
	{
		if (is_program_flag(argv[i]))
			continue ;
		if (!is_valid_num(argv[i]))
			exit_error(&a, NULL);
		val = ft_atol(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			exit_error(&a, NULL);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			exit_error(&a, NULL);
		new_node->value = (int)val;
		ft_lstadd_back(&a, new_node);
	}
	if (has_duplicates(a))
		exit_error(&a, NULL);
	return (a);
}
