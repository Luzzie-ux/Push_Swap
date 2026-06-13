/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+        */
/*      	                                  +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:01:17 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/12 12:30:53 by diferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				i;
	struct s_stack	*next;
}	t_stack;

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
/* Parsing e Validação */
t_stack	*parse_input(char **argv);
//A função principal de entrada. Lê os argumentos do terminal,
//converte-os (com atoi) e cria a lista ligada inicial na Stack A.
int		is_program_flag(char *str);
//Verifica se a string e uma flag
int		is_valid_num(char *str);
//Verifica se a string recebida é mesmo um número
//(se tem apenas dígitos e, no máximo, um sinal de + ou -).
int		has_duplicates(t_stack *a);
//Percorre a stack recém-criada para garantir que nenhum número se repete.
void	free_stack(t_stack **stack);
//Liberta a memória de todos os nós (com free) para evitar leaks.
void	exit_error(t_stack **a, t_stack **b);
//Função de socorro. Limpa as stacks e escreve "Error\n"
//no stderr se algo correr mal (ex: entrada inválida).
long	ft_atol(char *s);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

/* Métrica de Desordem e Utils */
double	compute_disorder(t_stack *a);
/*Percorre a stack e conta quantos pares estão mal ordenados. 
Divide esse total pelos pares disponiveis para dar um valor entre 0 e 1.*/
int		get_stack_size(t_stack *stack);
//Devolve o número total de elementos na stack.
void	set_index(t_stack *a);
//Organiza o index de todos os nodes da linked list de maior para o menor.
int		is_sorted(t_stack *stack);
/*Verifica se a stack já está perfeitamente ordenada, se estiver
o programa pode parar imediatamente.*/
t_stack	*get_min_node(t_stack *stack);
t_stack	*get_max_node(t_stack *stack);
int		get_node_pos(t_stack *stack, int target);
//get_min_node / get_max_node: Localizam o nó com o menor ou maior valor.
// get_pos devolve a posicao do node com o index correspondente.

/* bench struct utils and bench print functions */
t_bench	*get_bench(int *set_mode);
void	init_bench(double disorder, int mode);
void	count_op(char *op);
void	print_bench(void);

/* Ft_split e utils para o seu funcionamento */
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
/* Estratégias de Ordenação */
void	sort_adaptive(t_stack **a, t_stack **b, int mode);
//usa o valor da compute_disorder para decidir qual estratégia é a melhor.
void	sort_simple(t_stack **a, t_stack **b, int print);
/*O(n^2): Um algoritmo básico que usa selection sort para organizar
os ints dados*/
void	sort_medium(t_stack **a, t_stack **b, int print);
/*O(n/sqrt[n]): Usa chunks (dividir a stack em fatias). 
Envia os números por chunks para a Stack B para minimizar movimentos.*/
void	sort_complex(t_stack **a, t_stack **b, int print);
/*O(n log n): Um algoritmo mais complexo que usa Radix sort para organizar 
os ints de acordo com o valor em bits do seu index. */
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	sort_five(t_stack **a, t_stack **b, int print);
void	sort_three(t_stack **a, int print);
void	sort_two(t_stack **a, int print);
#endif
