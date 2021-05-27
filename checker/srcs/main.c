#include "checker.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	**arg;

	if (argc <= 1)
		return (0);
	arg = init_arg(&argc, argv);
	a = set_stack(argc, arg);
	b = init_stack();
	checker(a, b, argc);
	free_all(a, b, arg);
	return (0);
}
