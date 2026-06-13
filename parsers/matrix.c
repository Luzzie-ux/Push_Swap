/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:46:16 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/13 20:57:39 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
	if (!tmp)
		return (flags->flag_name = ERROR, NULL);
	result = ft_split(tmp, ' ');
	if (!result || !*result)
		return (flags->flag_name = ERROR, free(result), free(tmp), NULL);
	return (free(tmp), result);
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

void	*free_matrix(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (NULL);
}
