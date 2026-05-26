/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:43:37 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/26 12:05:17 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTS_H
# define SORTS_H

# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//prototipo

//main
int		flags(char *argv);
int		isnum(char *argv);
int		ft_atoi(const char *nptr);
int		parser(int argc, char **argv);
int		loop(int i, int argc, char **argv);

//stack functions

//lists
t_list	*extension(int check, int argc, char **argv);
t_list	*create_list(int *arr, int size);
void	free_list(t_list *head);

#endif