/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/08 16:04:16 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (ft_putstr_fd("ERROR", 2), 1);
	while (*argv)
	{
		ft_split(argv, ' ');
	}
	ft_printf("Program is over!");
	return (0);
}