/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:07:07 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/22 16:49:45 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	i = 0;
	int	*array;
	if (argc < 2)
		return (printf("ERROR: NOT ENOUGH ARGUMENTS"), 0);
	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (0);
	while (i < argc - 1)
	{
		array[i] = ft_atoi(argv[i + 1]);
		printf("pos[%d]=%d\n", i, array[i]);
		i++;
	}
	printf("\nend of loop");
	return (0);
}
