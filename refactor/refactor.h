/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refactor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:23:27 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/14 14:29:21 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFACTOR_H
# define REFACTOR_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*prototipos*/
typedef struct s_stack
{
	int				value;
	int				i;
	struct s_stack	*next;
}					t_stack;

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
	double		disorder;
}				t_flags;

/*libft*/
size_t	ft_strlen(char *s);
size_t	ft_phrlen(char **p);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);

/*push_swap*/
int		check_for_duple(char **copy);
int		check_for_letters(char *copy);
int		check_errors(char **nums);
void	*validate_nums(char **num, t_flags *flags);
void	validate_flags(char **arg, t_flags *flag);
void	*validate_args(char **args, t_flags *flags);
int		is_sorted(t_stack *stack);
int		get_stack_size(t_stack *stack);
void	free_list(t_stack *head);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value);
t_stack	*create_list(int *arr, int size);
void	set_index(t_stack *a);
void	*free_matrix(char **matrix);
char	*join(char *tmp, char **argv, int argc);
char	**matrix(int argc, char **argv, t_flags *flags);
t_stack	*setup(char **args, t_flags *flags);
int		execute(t_flags *flags, t_stack *a, t_stack *b);

/*methods*/



#endif