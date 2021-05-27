#include "push_swap.h"

int		is_whole_big(t_stack *a, int r, int pivot)
{
	while (r--)
	{
		if (a->stack->value <= pivot)
			return (0);
		a->stack = a->stack->next;
	}
	a->stack = a->head;
	return (1);
}

int		is_whole_small(t_stack *b, int r, int pivot)
{
	while (r--)
	{
		if (b->stack->value > pivot)
			return (0);
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	return (1);
}
