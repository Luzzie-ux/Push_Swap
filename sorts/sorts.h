/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:43:37 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/24 21:50:48 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTS_H
# define SORTS_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//prototipo

int		flags(char *argv);
int		isnum(char *argv);
void	free_list(t_list *head);
int		ft_atoi(const char *nptr);
int		parser(int argc, char **argv);
t_list	*create_list(int *arr, int size);
int		loop(int i, int argc, char **argv);

#endif