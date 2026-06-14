#include "refactor.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_phrlen(char **p)
{
	int	i;

	i = 0;
	if (!p || !*p)
		return (i);
	while (p[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *nptr)
{
	long		num;
	int			sign;
	char		*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)nptr;
	while (ptr && (*ptr == ' ' || *ptr == '\t'
			|| *ptr == '\n' || *ptr == '\r'
			|| *ptr == '\v' || *ptr == '\f'))
		ptr++;
	if (*ptr == '+')
		ptr++;
	else if (*ptr == '-')
	{
		sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (num * sign);
}

long	ft_atol(const char *nptr)
{
	long		num;
	long		sign;
	char		*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)nptr;
	while (ptr && (*ptr == ' ' || *ptr == '\t'
			|| *ptr == '\n' || *ptr == '\r'
			|| *ptr == '\v' || *ptr == '\f'))
		ptr++;
	if (*ptr == '+')
		ptr++;
	else if (*ptr == '-')
	{
		sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (num * sign);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*ps;
	unsigned char		*pd;

	ps = (unsigned const char *)src;
	pd = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*pd = *ps;
		pd++;
		ps++;
		n--;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*address;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	address = (void *)malloc(nmemb * size);
	if (address == NULL)
		return (NULL);
	ft_memset(address, 0, nmemb * size);
	return (address);
}

static int	count_word(const char *str, char delimiter)
{
	size_t	counter;
	int		i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i] != '\0')
		{
			counter++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
	}
	return (counter);
}

static char	*alloc(const char *s, int start, int end, char **string)
{
	int		i;
	char	*sword;

	i = 0;
	sword = malloc((end - start + 1) * sizeof(char));
	if (!sword)
	{
		while (string[i])
			free(string[i++]);
		free(string);
		return (NULL);
	}
	while (end > start)
		sword[i++] = s[start++];
	sword[i] = 0;
	return (sword);
}

static char	**ft(const char *s, char c, char **result)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (s[i] || start >= 0)
	{
		if (s[i] && s[i] != c && start < 0)
			start = i;
		else if ((!s[i] || s[i] == c) && start >= 0)
		{
			result[j] = alloc(s, start, i, result);
			if (!result[j])
				return (NULL);
			start = -1;
			j++;
		}
		i += (s[i] != '\0');
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (ft(s, c, result));
}

int	check_for_duple(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = i + 1;
		while (copy[j])
		{
			if (ft_atoi(copy[i]) == ft_atoi(copy[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_letters(char *copy)
{
	int	i;

	i = 0;
	if (copy[i] == '\0')
		return (1);
	if (copy[i] == '+' || copy[i] == '-')
		i++;
	while (copy[i])
	{
		if (!(copy[i] >= '0' && copy[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(char **num)
{
	int		i;
	long	val;

	i = 0;
	val = 0;
	if (check_for_duple(num))
		return (1);
	while (num[i])
	{
		val = ft_atol(num[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (1);
		else if (check_for_letters(num[i]))
			return (1);
		i++;
	}
	return (0);
}

void	validate_flags(char **arg, t_flags *flag)
{
	int	i;

	i = 0;
	while (arg[i] && (arg[i][0] == '-' && arg[i][1] == '-'))
	{
		if (!(ft_strncmp(arg[i], "--simple", 9)))
			((*flag).flag_name = SIMPLE);
		else if (!(ft_strncmp(arg[i], "--medium", 9)))
			((*flag).flag_name = MEDIUM);
		else if (!(ft_strncmp(arg[i], "--complex", 10)))
			((*flag).flag_name = COMPLEX);
		else if (!(ft_strncmp(arg[i], "--adaptative", 11)))
			((*flag).flag_name = ADAPTATIVE);
		else if (!(ft_strncmp(arg[i], "--bench", 8)))
			((*flag).bench = 1);
		else
			(*flag).flag_name = ERROR;
		i++;
	}
	if (arg[i] == NULL)
		(*flag).flag_name = ERROR;
	(*flag).advance += i;
}

void	*validate_nums(char **num, t_flags *flags)
{
	int	i;
	int	len;

	len = ft_phrlen(num);
	i = 0;
	if (check_errors(num))
		return (flags->flag_name = ERROR, NULL);
	flags->numbers = (int *)malloc(len * sizeof(int));
	if (!flags->numbers)
		return (flags->flag_name = ERROR, NULL);
	flags->nsize = len;
	while (num[i])
	{
		(*flags).numbers[i] = ft_atoi(num[i]);
		i++;
	}
	return (NULL);
}

void	*compute_disorder(t_flags *array)
{
	int		i;
	int		j;
	int		mistakes;
	int		total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < array->nsize)
	{
		j = i + 1;
		while (j < array->nsize)
		{
			total_pairs += 1;
			if (array->numbers[i] > array->numbers[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (array->flag_name = ERROR, NULL);
	return (array->disorder = ((double)mistakes / total_pairs), NULL);
}

void	*validate_args(char **args, t_flags *flags)
{
	flags->bench = 0;
	flags->advance = 0;
	flags->disorder = 0;
	if (!args || !*args)
		return (flags->flag_name = ERROR, NULL);
	if ((*args)[0] == '-' && (*args)[1] == '-')
		validate_flags(args, flags);
	if (flags->flag_name == ERROR)
		return (NULL);
	validate_nums(args + flags->advance, flags);
	if (flags->flag_name == ERROR)
		return (NULL);
	compute_disorder(flags);
	if (flags->disorder == 0)
		return (flags->flag_name = ERROR, free(flags->numbers), NULL);
	return (NULL);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->i > stack->next->i)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_stack	*ft_lstnew(int value)
{
	t_stack	*box;
	box = (t_stack *)malloc(sizeof(t_stack));
	if (!box)
		return (NULL);
	box->value = value;
	box->next = NULL;
	return (box);
}

t_stack	*create_list(int *arr, int size)
{
	int		i;
	t_stack	*head;
	t_stack	*tail;
	t_stack	*new_node;

	i = 0;
	head = NULL;
	tail = NULL;
	while (i < size)
	{
		new_node = ft_lstnew(arr[i++]);
		if (!new_node)
			return (free_stack(&head), NULL);
		if (!head)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
	}
	return (head);
}



void	*free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (NULL);
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (NULL);
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
	result = ft_split(tmp, ' ');
	if (!result)
		return (flags->flag_name = ERROR, free(result), free(tmp), NULL);
	return (free(tmp), result);
}

t_stack	*setup(char **args, t_flags *flags)
{
	t_stack	*a;

	validate_args(args, flags);
	if (flags->flag_name == ERROR)
		return (write(2, "Error\n", 6), free_matrix(args), exit(1), NULL);
	a = create_list(flags->numbers, flags->nsize);
	free(flags->numbers);
	flags->numbers = NULL;
	if (!a)
		return (write(2, "Error\n", 6), exit(1), NULL);
	set_index(a);
	return (a);
}


static void	print_disorder_to_bench(t_bench *b)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(b->disorder * 100);
	dec_part = (int)((b->disorder * 100 - int_part) * 100);
	if (dec_part < 0)
		dec_part = -dec_part;
	write(2, "[bench] disorder:  ", 19);
	if (dec_part < 10)
		ft_printf("%d.0%d%%\n", int_part, dec_part);
	else
		ft_printf("%d.%d%%\n", int_part, dec_part);
}

void	print_bench(void)
{
	t_bench	*b;

	b = get_bench(NULL);
	if (!b)
		return ;
	print_disorder_to_bench(b);
	ft_printf("[bench] strategy:  %s\n", b->strategy);
	ft_printf("[bench] total_ops: %d\n", b->total_operations);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra: %d  rrb: %d  rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}

t_bench	*get_bench(int *set_mode)
{
	static t_bench	bench;
	static int		mode = 0;

	if (set_mode)
		mode = *set_mode;
	if (mode == 0)
		return (NULL);
	return (&bench);
}

void	init_bench(double disorder, int mode, int bench)
{
	t_bench	*b;
	int		strategy_type;

	strategy_type = mode;
	b = get_bench(&bench);
	if (!b)
		return ;
	ft_bzero(b, sizeof(t_bench));
	b->disorder = disorder;
	if (strategy_type == SIMPLE)
		b->strategy = "Simple / O(n^2)";
	else if (strategy_type != MEDIUM && strategy_type != COMPLEX&& disorder < 0.2)
		b->strategy = "Adaptive / O(n^2)";
	else if (strategy_type == MEDIUM)
		b->strategy = "Medium / O(n√n)";
	else if (strategy_type != COMPLEX && disorder < 0.5)
		b->strategy = "Adaptive / O(n√n)";
	else if (strategy_type == COMPLEX)
		b->strategy = "Complex / O(n log n)";
	else
		b->strategy = "Adaptive / O(n log n)";
}

int	execute(t_flags *flags, t_stack **a, t_stack **b)
{
	init_bench(flags->disorder, flags->flag_name, flags->bench);
	if (flags->flag_name == SIMPLE)
		sort_simple(a, b, 1);
	else if (flags->flag_name == MEDIUM)
		sort_medium(a, b, 1);
	else if (flags->flag_name == COMPLEX)
		sort_complex(a, b, 1);
	else
		sort_adaptive(a, b, flags);
	print_bench();
	return (0);
}
