/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:58:53 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/11 15:00:40 by rodrpere         ###   ########.fr       */
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
	// if (!num[index])
	// 	return ((*flags).flag_name = ERROR, NULL);
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
	check_errors(flags, copy);
	if (did_split == 1)
		free_split(copy);
	return (NULL);
}

void	check_errors(t_flags *flags, char **copy)
{
	int j;

	j = 0;
	while (copy[j])
	{
		(*flags).numbers[j] = ft_atoi(copy[j]);
		j++;
	}
	return ;
}
/*

(*flags)->numbers[j] = ft_atoi(copy[j]);

copy = num
if (copy[index] && !copy[index + 1])
	copy = ft_split(copy[index], ' ');


	how do I make sure there is no letters inside copy if I cant see one argument at a time
while (!(*copy[n] >= 'A' && *copy[n] <= 'z'))
	n++;


*/