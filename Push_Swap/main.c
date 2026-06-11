/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/11 14:09:08 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_list	*stack;

	if (argc < 2)
		return (ft_putstr_fd("ERROR\n", 2), 1);
	validate_args(argv + 1, &flags);
	if (flags.flag_name == ERROR)
		return (ft_putstr_fd("FLAG ERROR\n", 2),1);
	stack = create_list(flags.numbers, flags.nsize);
	if (!stack)
		return (ft_putstr_fd("NOT ABLE TO MAKE LIST\n", 2),1);
	ft_printf("Program is over!\n");
	return (free(flags.numbers), free_list(stack), 0);
}
