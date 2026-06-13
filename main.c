/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/13 19:28:16 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_flags	flags;
	t_list	*a;
	t_list	*b;

	(void)b;
	if (argc < 2)
		return (ft_putstr_fd("Error\n", 2), 1);
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (ft_putstr_fd("Error\n", 2), free(args), 1);
	validate_args(args, &flags);
	if (flags.flag_name == ERROR)
		return (ft_putstr_fd("Error\n", 2), free_matrix(args), 1);
	a = create_list(flags.numbers, flags.nsize);
	ft_printf("Program is Over!\n");
	return (free_matrix(args), free(flags.numbers), free_list(a), 0);
}
