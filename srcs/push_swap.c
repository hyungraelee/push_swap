#include "push_swap.h"

int	push_swap(t_stack *a, t_stack *b, int r)
{
	if (a->cnt == 3 || a->cnt == 5)
		handle_little_input(a, b, r);
	else
		quicksort_in_a(a, b, r);
	free_all(a, b);
	return (1);
}
