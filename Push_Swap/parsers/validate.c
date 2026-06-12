/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:58:53 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 10:00:28 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	validate_args(char **args, t_flags *flags)
{
	(*flags).advance = 0;
	(*flags).bench = 0;
	(*flags).flag_name = ADAPTATIVE;
	if ((*args)[0] == '-' && (*args)[1] == '-')
		validate_flags(args, flags);
	if ((*flags).flag_name == ERROR)
		return ;
	validate_nums(args, (*flags).advance, flags);
	if ((*flags).flag_name == ERROR)
		return ;
	compute_disorder(flags);
}

void	validate_flags(char **arg, t_flags *flag)
{
	int	i;

	i = 0;
	while (arg[i] && (arg[i][0] == '-' && arg[i][1] == '-'))
	{
		if (!(ft_strncmp(arg[i], "--simple", 9)))
			((*flag).flag_name = SIMPLE);
		else if (!(ft_strncmp(arg[i], "--medium", 9)))
			((*flag).flag_name = MEDIUM);
		else if (!(ft_strncmp(arg[i], "--complex", 10)))
			((*flag).flag_name = COMPLEX);
		else if (!(ft_strncmp(arg[i], "--adaptative", 11)))
			((*flag).flag_name = ADAPTATIVE);
		else if (!(ft_strncmp(arg[i], "--bench", 8)))
			((*flag).bench = 1);
		else
			(*flag).flag_name = ERROR;
		i++;
	}
	if (arg[i] == NULL)
		(*flag).flag_name = ERROR;
	(*flag).advance += i;
}

void	*validate_nums(char **num, int index, t_flags *flags)
{
	char	**copy;
	int		did_split;

	did_split = 0;
	if (num[index] && !num[index + 1])
	{
		copy = ft_split(num[index], ' ');
		did_split = 1;
	}
	else
		copy = num;
	while (copy[index - (*flags).advance])
		index++;
	(*flags).numbers = malloc((index - (*flags).advance) * sizeof(int));
	if (!(*flags).numbers)
		return ((*flags).flag_name = ERROR, free_split(copy));
	(*flags).nsize = index - (*flags).advance;
	if (check_errors(flags, copy, did_split))
		return (free((*flags).numbers), NULL);
	if (did_split == 1)
		free_split(copy);
	return (NULL);
}

void	*compute_disorder(t_flags *array)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	array->disorder = 0;
	while (i < array->nsize)
	{
		j = i + 1;
		while (j < array->nsize)
		{
			total_pairs += 1;
			if (array->numbers[i] > array->numbers[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (array->disorder = (mistakes / total_pairs), NULL);
}
