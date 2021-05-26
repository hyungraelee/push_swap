#include "push_swap.h"

int	is_b_sorted(t_stack *b)
{
	if (b->cnt == 0)
		return (1);
	while (b->stack->next)
	{
		if (b->stack->value < b->stack->next->value)
		{
			b->stack = b->head;
			return (0);
		}
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	return (1);
}

int	is_a_sorted(t_stack *a)
{
	if (a->cnt == 0)
		return (1);
	while (a->stack->next)
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

int	is_finish(t_stack *a, t_stack *b)
{
	if (is_a_sorted(a))
	{
		if (b->cnt == 0 && b->stack == NULL)
			return (1);
	}
	return (0);
}

int	find_max_b(t_stack *b)
{
	int	cnt;
	int	cnt_max;
	int	max;

	cnt = 1;
	cnt_max = 1;
	max = b->stack->value;
	while (b->stack)
	{
		if (b->stack->value > max)
		{
			max = b->stack->value;
			cnt_max = cnt;
		}
		if (b->stack->next)
			b->stack = b->stack->next;
		else
			break ;
		cnt++;
	}
	b->max3[0] = max;
	b->stack = b->head;
	return (cnt_max);
}

void	get_pivot(t_stack *a, int r, int *pivot)
{
	int	min;
	int	max;

	min = a->stack->value;
	max = a->stack->value;
	while (r--)
	{
		if (a->stack->value < min)
			min = a->stack->value;
		else if (a->stack->value > max)
			max = a->stack->value;
		a->stack = a->stack->next;
	}
	a->stack = a->head;
	pivot[0] = (min + max) / 2;
	pivot[1] = (pivot[0] + min) / 2;
	if (pivot[0] == pivot[1])
		pivot[0] = pivot[1] + 1;
}

void	handle_3_in_a(t_stack *a)
{
	if (a->stack->value < a->stack->next->next->value && a->stack->next->next->value < a->stack->next->value)
	{
		rotate(a, NULL);
		swap(a, NULL);
		rev_rotate(a, NULL);
	}
	else if (a->stack->next->value < a->stack->value && a->stack->value < a->stack->next->next->value)
	{
		swap(a, NULL);
	}
	else if (a->stack->next->next->value < a->stack->value && a->stack->value < a->stack->next->value)
	{
		rotate(a, NULL);
		swap(a, NULL);
		rev_rotate(a, NULL);
		swap(a, NULL);
	}
	else if (a->stack->next->value < a->stack->next->next->value && a->stack->next->next->value < a->stack->value)
	{
		swap(a, NULL);
		rotate(a, NULL);
		swap(a, NULL);
		rev_rotate(a, NULL);
	}
	else if (a->stack->next->next->value < a->stack->next->value && a->stack->next->value < a->stack->value)
	{
		swap(a, NULL);
		rotate(a, NULL);
		swap(a, NULL);
		rev_rotate(a, NULL);
		swap(a, NULL);
	}
}

void	sort_a_to_b(t_stack *a, t_stack *b, int r)
{
	int	pivot[2];
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pb;
	int	tmp;
	int	tmp1;

	a->stack = a->head;
	if (r == 0 || r == 1)
		return ;
	else if (r == 2)
	{
		if (a->stack->value > a->stack->next->value)
			swap(a, NULL);
		return ;
	}
	else if (r == 3)
	{
		handle_3_in_a(a);
		return ;
	}
	get_pivot(a, r, pivot);
	cnt_ra = 0;
	cnt_rb = 0;
	cnt_pb = 0;
	while (r-- > 0)
	{
		if (a->stack->value > pivot[0])
		{
			rotate(a, NULL);
			cnt_ra++;
		}
		else
		{
			push(a, b, PUSH_B);
			cnt_pb++;
			if (b->head->value > pivot[1])
			{
				rotate(NULL, b);
				cnt_rb++;
			}
		}
	}
	tmp = cnt_ra;
	while (tmp-- > 0)
		rev_rotate(a, NULL);
	tmp1 = cnt_rb;
	while (tmp1-- > 0)
		rev_rotate(NULL, b);
	sort_a_to_b(a, b, cnt_ra);
	sort_b_to_a(a, b, cnt_rb);
	sort_b_to_a(a, b, cnt_pb - cnt_rb);
}

void	handle_3_in_b(t_stack *b)
{
	if (b->stack->value < b->stack->next->value && b->stack->next->value < b->stack->next->next->value)
	{
		swap(NULL, b);
		rotate(NULL, b);
		swap(NULL, b);
		rev_rotate(NULL, b);
		swap(NULL, b);
	}
	else if (b->stack->value < b->stack->next->next->value && b->stack->next->next->value < b->stack->next->value)
	{
		swap(NULL, b);
		rotate(NULL, b);
		swap(NULL, b);
		rev_rotate(NULL, b);
	}
	else if (b->stack->next->value < b->stack->value && b->stack->value < b->stack->next->next->value)
	{
		rotate(NULL, b);
		swap(NULL, b);
		rev_rotate(NULL, b);
		swap(NULL, b);
	}
	else if (b->stack->next->next->value < b->stack->value && b->stack->value < b->stack->next->value)
	{
		swap(NULL, b);
	}
	else if (b->stack->next->value < b->stack->next->next->value && b->stack->next->next->value < b->stack->value)
	{
		rotate(NULL, b);
		swap(NULL, b);
		rev_rotate(NULL, b);
	}
}

void	sort_b_to_a(t_stack *a, t_stack *b, int r)
{
	int	pivot[2];
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	tmp;
	int	tmp1;

	b->stack = b->head;
	if (r == 0)
		return ;
	else if (r == 1)
	{
		push(a, b, PUSH_A);
		return ;
	}
	else if (r == 2)
	{
		if (b->stack->value < b->stack->next->value)
			swap(NULL, b);
		push(a, b, PUSH_A);
		push(a, b, PUSH_A);
		return ;
	}
	else if (r == 3)
	{
		handle_3_in_b(b);
		push(a, b, PUSH_A);
		push(a, b, PUSH_A);
		push(a, b, PUSH_A);
		return ;
	}
	get_pivot(b, r, pivot);
	cnt_ra = 0;
	cnt_rb = 0;
	cnt_pa = 0;
	while (r-- > 0)
	{
		if (b->stack->value > pivot[1])
		{
			push(a, b, PUSH_A);
			cnt_pa++;
			if (a->head->value < pivot[0])
			{
				rotate(a, NULL);
				cnt_ra++;
			}
		}
		else
		{
			rotate(NULL, b);
			cnt_rb++;
		}
	}
	sort_a_to_b(a, b, cnt_pa - cnt_ra);
	tmp = cnt_rb;
	while (tmp-- > 0)
		rev_rotate(NULL, b);
	tmp1 = cnt_ra;
	while (tmp1-- > 0)
		rev_rotate(a, NULL);
	sort_a_to_b(a, b, cnt_ra);
	sort_b_to_a(a, b, cnt_rb);
}

void	quick_sort(t_stack *a, t_stack *b, int r)
{
	sort_a_to_b(a, b, r);
}

int	push_swap(t_stack *a, t_stack *b, int r)
{
	quick_sort(a, b, r);
	// free_all(a, b);
	return (1);
}
