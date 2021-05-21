#include "push_swap.h"

void	rev_rotate_stack(t_stack *a)
{
	a->last->next = a->first;
	a->first->prev = a->last;
	a->first = a->last;
	a->last = a->last->prev;
	a->second = a->first->next;
	a->first->prev = NULL;
	a->last->next = NULL;
	a->stack = a->first;
}

void	rev_rotate(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		rev_rotate_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		rev_rotate_stack(b);
	}
}
