#include "push_swap.h"

void	rotate_stack(t_stack *a)
{
	a->last->next = a->first;
	a->first->prev = a->last;
	a->last = a->first;
	a->first = a->second;
	a->second = a->first->next;
	a->first->prev = NULL;
	a->last->next = NULL;
	a->stack = a->first;
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
