#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} t_strat;

typedef struct s_flags
{
	t_strat flag_name;
	int bench;
	int advance;
	int *numbers;
	int nsize;
	float disorder;
} t_flags;

size_t ft_strlen(char *s)
{
	size_t i;

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

char *join(char *tmp, char **argv, int argc)
{
	int pos;
	int i;
	int j;

	pos = 0;
	i = 0;
	if (!tmp || !argv || !*argv)
		return (printf("Someone is NULL\n"), NULL);
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
			if (ft_strcmp(copy[i], copy[j]) == 0)
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
	while (copy[i])
	{
		if (copy[i] >= 65 && copy[i] <= 126)
			return (1);
		i++;
	}
	return (0);
}

int	check_for_signs(char *copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		if (copy[i + 1] == '\0' && (copy[i] == '-' || copy[i] == '+'))
			return (1);
		else if ((copy[i] >= '!' && copy[i] <= '*') || copy[i] == ',')
			return (1);
		else if (copy[i] == '.' || (copy[i] >= ':' && copy[i] <= '@'))
			return (1);
		else if (copy[i] == '/')
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
	while (num[i])
	{
		val = atol(num[i]);
		if (val > 2147483647 || val < -2147483648)
			return (printf("Overflow\n"), 1);
		else if (check_for_duple(num))
			return (printf("Found duple\n"), 1);
		else if(check_for_letters(num[i]))
			return (printf("Found letter\n"), 1);
		else if(check_for_signs(num[i]))
			return (printf("Found signs\n"), 1);
		i++;
	}
	return (0);
}

void	*compute_disorder(t_flags *array)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	array->disorder = 0;
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
	return (array->disorder = (mistakes / total_pairs), NULL);
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
	int len;

	len = ft_phrlen(num);
	i = 0;
	if(check_errors(num))
		return (printf("Found Error\n"), flags->flag_name = ERROR, NULL);
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

void	validate_args(char **args, t_flags *flags)
{
	(*flags).advance = 0;
	(*flags).bench = 0;
	(*flags).flag_name = ADAPTATIVE;
	if (!args || !*args)
		return ;
	if ((*args)[0] == '-' && (*args)[1] == '-')
		validate_flags(args, flags);
	if ((*flags).flag_name == ERROR)
		return ;
	validate_nums(args + flags->advance, flags);
	if ((*flags).flag_name == ERROR)
		return ;
	compute_disorder(flags);
}

char	**matrix(int argc, char **argv, t_flags *flags)
{
	char	**result;
	char	*tmp;
	size_t	total_lenght;
	int		i;

	i = 0;
	total_lenght = 0;
	flags->flag_name = ADAPTATIVE;
	while (i < argc)
	{
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
	if (!result)
		return (flags->flag_name = ERROR, free(tmp),  NULL);
	return (free(tmp), result);
}

int main(int argc, char **argv)
{
	t_flags flags;
	char **args;

	if (argc < 2)
		return (printf("Not Enough Arguments\n"), 1);
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (printf("Something Went Wrong\n"), 1);
	validate_args(args, &flags);
	if (flags.flag_name == ERROR)
		return (free_matrix(args), printf("Validation went wrong\n"), 1);
	return (free_matrix(args), free(flags.numbers), printf("Program is Over!\n"), 0);
}