#include "checker.h"

static void	rev_rotate_stack(t_stack *a)
{
	if (a->cnt > 1)
	{
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->head = a->tail;
		a->tail = a->tail->prev;
		a->head->prev = NULL;
		a->tail->next = NULL;
		a->stack = a->head;
	}
}

void		rev_rotate(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else if (a && !b)
		rev_rotate_stack(a);
	else if (!a && b)
		rev_rotate_stack(b);
}
