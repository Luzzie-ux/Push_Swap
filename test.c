#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	*free_split(char **string)
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

char **matrix(int argc, char **argv, t_flags *flags)
{
	char 	**result;
	char 	*tmp;
	size_t 	total_lenght;
	int 	i;

	i = 0;
	total_lenght = 0;
	while (i < argc)
	{
		total_lenght += ft_strlen(argv[i]);
		i++;
	}
	total_lenght += argc;
	tmp = (char *)malloc((total_lenght + 1) * sizeof(char));
	if (!tmp)
		return (printf("malloc error\n"), flags->flag_name = ERROR, NULL);
	tmp = join(tmp, argv, argc);
	if (!tmp)
		return (printf("TMP is NULL\n"), NULL);
	result = ft_split(tmp, ' ');
	if (!result)
		return (flags->flag_name = ERROR, free(tmp),  NULL);
	return (free(tmp), result);
}

int main(int argc, char **argv)
{
	t_flags flags;
	flags.flag_name = SIMPLE;
	char **args;

	if (argc < 2)
		return (printf("Not Enough Arguments\n"), 1);
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (printf("Something Went Wrong\n"), 1);
	return (free_split(args), 0);
}