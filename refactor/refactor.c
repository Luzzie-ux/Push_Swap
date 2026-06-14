#include "refactor.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_flags	flags;
	t_stack	*a;
	// t_stack	*b;
	/*check for valid input*/
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	/*arguments allocation section*/
	args = matrix(argc - 1, argv + 1, &flags);
	if (!args || flags.flag_name == ERROR)
		return (write(2, "Error\n", 6), free(args), 1);
	/*section to be refactored into a new function*/
	a = setup(args, &flags);
	/*section saved for the execute function*/
	/*end of program section*/ 
	write(1, "Program is Over!\n", 17);
	return (free_matrix(args), free(flags.numbers), free_list(a), 0);
}
