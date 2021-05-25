#include "push_swap.h"

void	rotate_stack(t_stack *a)
{
	if (a->cnt > 1)
	{
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail = a->head;
		a->head = a->tail->next;
		a->head->prev = NULL;
		a->tail->next = NULL;
		a->stack = a->head;
	}
}

void	rotate(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		rotate_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("rb\n", STDOUT_FILENO);
		rotate_stack(b);
	}
}
