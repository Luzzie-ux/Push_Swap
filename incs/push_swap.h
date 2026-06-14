/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:01:31 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 18:20:12 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/*prototipos*/

//stack struct
typedef struct s_stack
{
	int				value;
	int				i;
	struct s_stack	*next;
}					t_stack;

//strategy enum
typedef enum e_strat
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	ERROR
}	t_strat;

//flaging struct
typedef struct s_flags
{
	t_strat		flag_name;
	int			bench;
	int			advance;
	int			*numbers;
	int			nsize;
	double		disorder;
}				t_flags;

//bench struct
typedef struct s_bench
{
	double	disorder;
	char	*strategy;
	int		total_operations;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

/*push_swap*/

void	*free_matrix(char **matrix);
char	*join(char *tmp, char **argv, int argc);
char	**matrix(int argc, char **argv, t_flags *flags);

int		check_for_duple(char **copy);
int		check_for_signs(char *copy);
int		check_for_letters(char *copy);
int		check_errors(char **nums);

void	*compute_disorder(t_flags *array);
void	*validate_nums(char **num, t_flags *flags);
void	validate_flags(char **arg, t_flags *flag);
void	*validate_args(char **args, t_flags *flags);

int		is_sorted(t_stack *stack);
int		get_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value);
t_stack	*create_list(int *arr, int size);
void	set_index(t_stack *a);

t_stack	*setup(char **args, t_flags *flags);

void	print_bench(void);

t_bench	*get_bench(int *set_mode);
void	init_bench(double disorder, int mode, int bench);

int		execute(t_flags *flags, t_stack **a, t_stack **b);

/*methods*/

void	count_op(char *op);
t_stack	*get_max_node(t_stack *stack);
t_stack	*get_min_node(t_stack *stack);
int		get_node_pos(t_stack *stack, int target);

/* Operações - Swap - Trocam a posição do primeiro com o segundo elemento.
Se print for 1, escreve "sa", "sb" ou "ss".*/
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

/* Operações - Push - Movem o topo de uma stack para a outra.
Ex: pb retira de a e coloca no topo de b. */
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

/* Operações - Rotate - O primeiro elemento da stack passa a ser o último 
(deslocam tudo para cima). */
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

/* Operações - Reverse Rotate - O último elemento da stack passa a ser o 
primeiro (deslocam tudo para baixo).*/
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/*sorting*/

void	sort_two(t_stack **a, int print);
void	sort_three(t_stack **a, int print);
void	sort_five(t_stack **a, t_stack **b, int print);

/*algos*/

void	sort_simple(t_stack **a, t_stack **b, int print);
void	sort_adaptive(t_stack **a, t_stack **b, t_flags *mode);
void	sort_complex(t_stack **a, t_stack **b, int print);
void	sort_medium(t_stack **a, t_stack **b, int print);


#endif