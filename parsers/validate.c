/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:58:53 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 20:35:42 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	*validate_args(char **args, t_flags *flags)
{
	flags->bench = 0;
	flags->advance = 0;
	flags->disorder = 0;
	if (!args || !*args)
		return (flags->flag_name = ERROR, NULL);
	if ((*args)[0] == '-' && (*args)[1] == '-')
		validate_flags(args, flags);
	if (flags->flag_name == ERROR)
		return (NULL);
	validate_nums(args + flags->advance, flags);
	if (flags->flag_name == ERROR)
		return (NULL);
	compute_disorder(flags);
	if (flags->flag_name == ERROR)
		return (free(flags->numbers), NULL);
	return (NULL);
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
		else if (!(ft_strncmp(arg[i], "--adaptive", 9)))
			((*flag).flag_name = ADAPTIVE);
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

void	*validate_nums(char **num, t_flags *flags)
{
	int	i;
	int	len;

	len = ft_phrlen(num);
	i = 0;
	if (check_errors(num))
		return (flags->flag_name = ERROR, NULL);
	flags->numbers = (int *)malloc(len * sizeof(int));
	if (!flags->numbers)
		return (flags->flag_name = ERROR, NULL);
	flags->nsize = len;
	while (num[i])
	{
		(*flags).numbers[i] = ft_atoi(num[i]);
		i++;
	}
	return (NULL);
}

t_stack	*setup(char **args, t_flags *flags)
{
	t_stack	*a;

	validate_args(args, flags);
	if (flags->flag_name == ERROR)
		return (write(2, "Error\n", 6), free_matrix(args), exit(1), NULL);
	a = create_list(flags->numbers, flags->nsize);
	free(flags->numbers);
	flags->numbers = NULL;
	if (!a)
		return (write(2, "Error\n", 6), exit(1), NULL);
	set_index(a);
	return (a);
}
