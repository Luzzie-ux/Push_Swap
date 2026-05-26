/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:03:43 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/26 11:26:38 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

int	flags(char *argv)
{
	int	flag;

	flag = 1;
	if (argv[0] == '-' && argv[1] == '-')
	{
		if (ft_strncmp(argv, "--simple", 9) == 0 && argv[8] == '\0')
			flag = 1;
		else if (ft_strncmp(argv, "--medium", 9) == 0 && argv[8] == '\0')
			flag = 2;
		else if (ft_strncmp(argv, "--complex", 10) == 0 && argv[9] == '\0')
			flag = 3;
		else if (ft_strncmp(argv, "--adaptive", 11) == 0 && argv[10] == '\0')
			flag = 4;
		else if (ft_strncmp(argv, "--bench", 8) == 0 && argv[7] == '\0')
			return (10);
		else
			return (-1);
	}
	return (flag -= 1);
}

int	parser(int argc, char **argv)
{
	int	i;
	int	skip;
	int	result;

	i = 1;
	result = loop(i, argc, argv);
	if (result == -1)
		return (-1);
	skip = result / 100;
	i = 1 + skip;
	while (i < argc)
	{
		if (!isnum(argv[i]))
			return (-1);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*array;
	/* t_tree	*list; */
	t_list	*stack_a;
	int		check;
	int		skip;
	// int		strat;
	// int		bench;

	i = 0;
	if (argc <= 3)
		return (printf("ERROR\n"), 0);
	check = parser(argc, argv);
	if (check == -1)
		return (printf("ERROR\n"), 0);
	// bench = check % 10;
	// strat = (check / 10) % 10;
	skip = check / 100;
	array = (int *)malloc(sizeof(int) * (argc - 1 - skip));
	if (!array)
		return (0);
	while (i < ((argc - 1 - skip)))
	{
		array[i] = ft_atoi(argv[i + 1 + skip]);
		printf("stack_a[%d]=%d\n", i, array[i]);
		i++;
	}
	stack_a = create_list(array, argc - 1 - skip);
	printf("stack_a size: %d\n", ft_lstsize(stack_a));
	return (free_list(stack_a), free(array), 0);
}

/* list = insertion(array, argc - 1 - skip);
printf("tree is %d deep", tree_size(list)); */