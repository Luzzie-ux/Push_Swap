/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:58:53 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/09 18:51:15 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	validate_args(int argc, char **args, t_flags **flags)
{
	int i;

	if (!*args || !args)
		return ;
	if (*args[0] == '-' && args[1] == '-')
		validate_flags(args, flags);
	else
	{
		i = (*flags)->advance;
		validate_nums(args, i, flags);
	}
}

static void validate_flags(char **arg, t_flags **flag)
{
	int	i;
	
	i = 0;
	(*flag)->bench = 0;
	(*flag)->advance = 0;
	(*flag)->flag_name = ADAPTATIVE;
	while (arg[i])
	{
		if (!(ft_strncmp(arg[i], "--simple", 9)))
			((*flag)->flag_name = SIMPLE);
		else if (!(ft_strncmp(arg[i], "--medium", 9)))
			((*flag)->flag_name = MEDIUM);
		else if (!(ft_strncmp(arg[i], "--complex", 10)))
			((*flag)->flag_name = COMPLEX);
		else if (!(ft_strncmp(arg[i], "--adaptative", 11)))
			((*flag)->flag_name = ADAPTATIVE);
		else if (!(ft_strncmp(arg[i], "--bench", 8)))
			((*flag)->bench = 1);
		else
			(*flag)->flag_name = ERROR;
		i++;
	}
	(*flag)->advance += i;
}

void	validate_nums(char **num, int index, t_flags **flags)
{
	int		i;
	int		j;
	char 	**copy;

	i = index;
	j = 0;
	if (!num || !*num)
		(*flags)->flag_name = ERROR;
	if (num[i] && !num[i + 1])
		copy = ft_split(*num, ' ');
	else
		copy = num;
	while (copy[i])
		i++;
	(*flags)->numbers = malloc(i * sizeof(int));
	while (copy[j])
	{
		(*flags)->numbers[j] = ft_atoi(copy[j]);
		j++;
	}
}
