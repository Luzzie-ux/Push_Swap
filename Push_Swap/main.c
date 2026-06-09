/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/09 16:50:47 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	/* char	*arg; */
	t_flags *flags;

	if (argc < 2 || !*argv || !argv)
		return (ft_putstr_fd("ERROR", 2), 1);
	flags = (t_flags *)malloc(sizeof(t_flags));
	validate_args(argc, argv, flags);
	/* arg = ft_gets(argc, argv, &flags);
	if (!arg)
		return (free(arg), 1); */
	if (flags->flag_name == ERROR)
		return (1);
	ft_printf("Program is over!");
	return (0);
}
