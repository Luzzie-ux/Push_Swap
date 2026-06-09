/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:58:53 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/09 18:36:28 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

char	*ft_gets(char **args)
{
	char		*result;
	size_t		size;
	int			i;

	i = 0;
	if (!*args || !args)
		return (NULL);
	while (args[i])
	{
		size = ft_strlen(args[i + 1]);
		result = (char *)malloc(size + 1 * sizeof(char));
		if (!result)
			return (NULL);
		result = ft_memcpy(result, args[i + 1], size);
		result[size] = '\0';
		i++;
	}
	return (result);
}

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
	char	*result;
	char 	**copy;

	i = index;
	if (!num)
		(*flags)->flag_name = ERROR;
	while (i)
	{
		
	}
	result = ft_gets(num);
	copy = ft_split(result, ' ');
	
}

static int	phrase_len(char **s)
{
	int	i;

	i = 0;
	if (!*s || !s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

