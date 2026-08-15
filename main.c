/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/15 12:10:35 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf/ft_fprintf.h"
#include "incs/push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_flags	flags;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	flags.flag_name = ADAPTIVE;
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (ft_fprintf(2, "Error\n"), free(args), 1);
	a = setup(args, &flags);
	b = NULL;
	execute(&flags, &a, &b);
	return (free_matrix(args), free_stack(&a), 0);
}
