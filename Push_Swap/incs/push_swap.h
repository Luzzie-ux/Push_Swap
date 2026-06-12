/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:01:31 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/12 09:45:06 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				data;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef enum e_strat
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
	ERROR
}	t_strat;

typedef struct s_flags
{
	t_strat		flag_name;
	int			bench;
	int			advance;
	int			*numbers;
	int			nsize;
	float		disorder;
}	t_flags;

int		ft_lstsize(t_list *lst);

void	free_list(t_list *head);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

void	validate_flags(char **arg, t_flags *flag);
void	*validate_nums(char **num, int index, t_flags *flags);
void	validate_args(char **args, t_flags *flags);

void	*free_split(char **string);
int		check_errors(t_flags *flags, char **copy, int check);
void	*check_for_duple(char **copy, t_flags *flags);
void 	*check_for_letters(char *copy, t_flags *flags);
void 	*check_for_signs(char *copy, t_flags *flags);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_b, t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*create_list(int *arr, int size);

#endif