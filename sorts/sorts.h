/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:43:37 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/01 20:09:16 by rodrpere         ###   ########.fr       */
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
typedef struct s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;

}					t_list;

int		flags(char *argv);
int		isnum(char *argv);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *nptr);
int		compute_disorder(t_list *a);
int		parser(int argc, char **argv);
int		loop(int i, int argc, char **argv);

void	free_list(t_list *head);
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));

void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_b, t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*create_list(int *arr, int size);
t_list	*extension(int check, int argc, char **argv);
t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));

#endif