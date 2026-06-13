/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/13 18:20:13 by rodrpere         ###   ########.fr       */
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
		return (ft_putstr_fd("ERROR\n", 2), 1);
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (free(args), ft_putstr_fd("Something Went Wrong\n", 2), 1);
	validate_args(args, &flags);
	if (flags.flag_name == ERROR)
		return (free_matrix(args), free(flags.numbers), ft_putstr_fd("Validation went wrong\n", 2), 1);
	a = create_list(flags.numbers, flags.nsize);
	if (!a)
		return (ft_putstr_fd("NOT ABLE TO MAKE LIST\n", 2), 1);
	free_list(a);
	return (free_matrix(args), free(flags.numbers), ft_putstr_fd("Program is Over!\n", 2), 0);
}
