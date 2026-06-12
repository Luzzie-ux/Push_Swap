/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 22:16:52 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_flags	flags;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (ft_putstr_fd("ERROR\n", 2), 1);
	args = matrix(argc - 1, argv + 1, &flags);
	validate_args(args, &flags);
	if (flags.flag_name == ERROR)
		return (ft_putstr_fd("FLAG ERROR\n", 2), 1);
	a = create_list(flags.numbers, flags.nsize);
	if (!a)
		return (ft_putstr_fd("NOT ABLE TO MAKE LIST\n", 2), 1);
	ft_printf("Program is over!\n");
	return (free(flags.numbers), free_list(a), 0);
}
