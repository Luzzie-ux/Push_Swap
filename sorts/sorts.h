/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:43:37 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/25 18:32:02 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTS_H
# define SORTS_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//prototipo
typedef struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

int		flags(char *argv);
int		isnum(char *argv);
int		ft_atoi(const char *nptr);
int		parser(int argc, char **argv);
int		loop(int i, int argc, char **argv);

t_tree	*new_node(void *content);
t_tree	*insertion(int *array, int size);
void	insert(t_tree **root, int value);
int		tree_size(t_tree *root);

#endif