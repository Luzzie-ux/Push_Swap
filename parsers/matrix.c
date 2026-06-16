/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:46:16 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 17:50:56 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	*free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (NULL);
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (NULL);
}

char	*join(char *tmp, char **argv, int argc)
{
	int	pos;
	int	i;
	int	j;

	pos = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			tmp[pos++] = argv[i][j++];
		tmp[pos++] = ' ';
		i++;
	}
	tmp[pos] = '\0';
	return (tmp);
}

char	**matrix(int argc, char **argv, t_flags *flags)
{
	char	**result;
	char	*tmp;
	size_t	total_lenght;
	int		i;

	i = 0;
	total_lenght = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || (argv[i][0] == ' ' && argv[i][1] == '\0'))
			return (write(2, "Error\n", 6), exit(1), NULL);
		total_lenght += ft_strlen(argv[i]);
		i++;
	}
	total_lenght += argc;
	tmp = (char *)malloc((total_lenght + 1) * sizeof(char));
	if (!tmp)
		return (flags->flag_name = ERROR, NULL);
	tmp = join(tmp, argv, argc);
	result = ft_split(tmp, ' ');
	if (!result)
		return (flags->flag_name = ERROR, free(result), free(tmp), NULL);
	return (free(tmp), result);
}

int	execute(t_flags *flags, t_stack **a, t_stack **b)
{
	init_bench(flags->disorder, flags->flag_name, flags->bench);
	if (flags->flag_name == SIMPLE)
		sort_simple(a, b, 1);
	else if (flags->flag_name == MEDIUM)
		sort_medium(a, b, 1);
	else if (flags->flag_name == COMPLEX)
		sort_complex(a, b, 1);
	else
		sort_adaptive(a, b, flags);
	print_bench();
	return (0);
}
