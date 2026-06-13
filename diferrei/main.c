/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:37:02 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 12:30:19 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	is_flag(char **args, char *flag)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], "--bench") == 0 && args[i + 1])
		{
			if (args[i + 1] && ft_strcmp(args[i + 1], "--simple") == 0)
				return (2);
			if (args[i + 1] && ft_strcmp(args[i + 1], "--medium") == 0)
				return (3);
			if (args[i + 1] && ft_strcmp(args[i + 1], "--complex") == 0)
				return (4);
			if (ft_strcmp(flag, "--bench") == 0)
				return (1);
		}
		if (ft_strcmp(args[i], flag) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static char	**allocate_args(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	char	**result;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0' || (argv[i][0] == ' ' && argv[i][1] == '\0'))
			return (write(2, "Error\n", 6), exit(1), NULL);
	}
	i = 0;
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (++i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
	}
	result = ft_split(joined, ' ');
	free(joined);
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		bench;

	if (argc < 2)
		return (0);
	args = allocate_args(argc, argv);
	if (!args || !args[0])
		return (free_matrix(args), 0);
	a = parse_input(args);
	set_index(a);
	b = NULL;
	bench = is_flag(args, "--bench");
	init_bench(compute_disorder(a), bench);
	if (is_flag(args, "--simple") && !bench)
		sort_simple(&a, &b, 1);
	else if (is_flag(args, "--medium") && !bench)
		sort_medium(&a, &b, 1);
	else if (is_flag(args, "--complex") && !bench)
		sort_complex(&a, &b, 1);
	else
		sort_adaptive(&a, &b, bench);
	print_bench();
	return (free_stack(&a), free_stack(&b), free_matrix(args), 0);
}
