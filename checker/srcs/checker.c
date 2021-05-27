#include "checker.h"

int		is_push(char *operation)
{
	return (!ft_strcmp("pa", operation) || !ft_strcmp("pb", operation));
}

int		is_swap(char *operation)
{
	return	(!ft_strcmp("sa", operation) || !ft_strcmp("sb", operation) || !ft_strcmp("ss", operation));
}

int		is_rotate(char *operation)
{
	return (!ft_strcmp("ra", operation) || !ft_strcmp("rb", operation) || !ft_strcmp("rr", operation));
}

int		is_rev_rotate(char *operation)
{
	return (!ft_strcmp("rra", operation) || !ft_strcmp("rrb", operation) || !ft_strcmp("rrr", operation));
}

void	push_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("pa", operation))
		push(a, b, PUSH_A);
	else if (!ft_strcmp("pb", operation))
		push(a, b, PUSH_B);
}

void	swap_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("sa", operation))
		swap(a, NULL);
	else if (!ft_strcmp("sb", operation))
		swap(NULL, b);
	else if (!ft_strcmp("ss", operation))
		swap(a, b);
}
void	rotate_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("ra", operation))
		rotate(a, NULL);
	else if (!ft_strcmp("rb", operation))
		rotate(NULL, b);
	else if (!ft_strcmp("rr", operation))
		rotate(a, b);
}
void	rev_rotate_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("rra", operation))
		rev_rotate(a, NULL);
	else if (!ft_strcmp("rrb", operation))
		rev_rotate(NULL, b);
	else if (!ft_strcmp("rrr", operation))
		rev_rotate(a, b);
}

int	is_a_sorted(t_stack *a, int r)
{
	if (a->cnt == 0)
		return (1);
	while (r-- > 1)
	{
		if (a->stack->value > a->stack->next->value)
		{
			a->stack = a->head;
			return (0);
		}
		a->stack = a->stack->next;
	}
	a->stack = a->head;
	return (1);
}

void	print_ok(void)
{
	ft_putstr_fd(B_GREEN, STDOUT_FILENO);
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	ft_putstr_fd(C_RESET, STDOUT_FILENO);
}

void	print_ko(void)
{
	ft_putstr_fd(B_RED, STDOUT_FILENO);
	ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_putstr_fd(C_RESET, STDOUT_FILENO);
}

void	check_sort(t_stack *a, t_stack *b, int r)
{
	if (is_a_sorted(a, r))
		if (b->stack == NULL)
			print_ok();
		else
			print_ko();
	else
		print_ko();
}

void	checker(t_stack *a, t_stack *b, int r)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		if (is_push(buf))
			push_handler(a, b, buf);
		else if (is_swap(buf))
			swap_handler(a, b, buf);
		else if (is_rotate(buf))
			rotate_handler(a, b, buf);
		else if (is_rev_rotate(buf))
			rev_rotate_handler(a, b, buf);
	}
	if (buf)
		free(buf);
	check_sort(a, b, r);
}
