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

int	check_finish(t_stack *a, t_stack *b)
{
	if (is_a_sorted(a))
	{
		if (b->cnt == 0 && b->stack == NULL)
			return (1);
	}
	return (0);
}

int	is_finish(t_stack *a, t_stack *b, int *operate)
{
	if (check_finish(a, b))
		return (1);
	if (a->cnt == 2)
	{
		if (a->stack->value > a->stack->next->value)
			*operate |= SA;
	}
	else
	{
		if (a->head->value < a->head->next->value && a->head->next->value < a->tail->value)
			*operate |= PB;
		else if (a->head->value < a->tail->value && a->tail->value < a->head->next->value)
			*operate |= RRA;
		else if (a->head->next->value < a->head->value && a->head->value < a->tail->value)
			*operate |= SA;
		else if (a->tail->value < a->head->value && a->head->value < a->head->next->value)
			*operate |= RRA;
		else if (a->head->next->value < a->tail->value && a->tail->value < a->head->value)
			*operate |= RA;
		else if (a->tail->value < a->head->next->value && a->head->next->value < a->head->value)
			*operate |= SA;
	}
	return (0);
}

void	sort_b(t_stack *b, int *operate)
{
	while (b->head->value > b->tail->value)
	{
			rev_rotate(NULL, b, operate);
			swap(NULL, b, operate);
	}
	while (b->head->value < b->tail->value)
			rotate(NULL, b, operate);
}

int	push_swap(t_stack *a, t_stack *b)
{
	int	operate;

	operate = 0;
	while (!is_finish(a, b, &operate))
	{
		if (is_a_sorted(a) && a->cnt == 2)
		{
			if (is_b_sorted(b))
			{
				while (!is_finish(a, b, &operate))
					push(a, b, PUSH_A, &operate);
				return (1);
			}
			else
			{
				sort_b(b, &operate);
			}
		}
		else
		{
			if (is_b_sorted(b))
			{
				if (operate & PB)
					push(a, b, PUSH_B, &operate);
				else if (operate & SA)
					swap(a, NULL, &operate);
				else if (operate & RA)
					rotate(a, NULL, &operate);
				else if (operate & RRA)
					rev_rotate(a, NULL, &operate);
			}
			else if (operate & PB)
			{
				sort_b(b, &operate);
			}
			else
			{
				if (b->cnt == 2)
				{
					if (operate & SA)
						swap(a, b, &operate);
					else if (operate & RA)
						rotate(a, b, &operate);
					else if (operate & RRA)
						rev_rotate(a, b, &operate);
				}
				else
				{
					if (b->head->value > b->tail->value)
					{
						if (operate & RRA)
							rev_rotate(a, b, &operate);
						else
							rev_rotate(NULL, b, &operate);
						if (operate & SA)
							swap(a, b, &operate);
						else
							swap(NULL, b, &operate);
					}
					else if (b->head->value < b->tail->value)
					{
						if (operate & RA)
							rotate(a, b, &operate);
						else
							rotate(NULL, b, &operate);
					}
				}
			}
		}
	}
	// free_all
	return (1);
}
