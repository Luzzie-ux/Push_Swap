#include "refactor.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_flags	flags;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	flags.flag_name = ADAPTATIVE;
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (write(2, "Error\n", 6), free(args), 1);
	a = setup(args, &flags);
	b = NULL;
	execute(&flags, &a, &b);
	write(1, "Program is Over!\n", 17);
	return (free_matrix(args), free_stack(&a), 0);
}
