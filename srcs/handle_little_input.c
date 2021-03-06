/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_little_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:14 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:22:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	only_3_input(t_stack *a)
{
	if (a->head->value < a->tail->value && \
	a->tail->value < a->head->next->value)
	{
		swap(a, NULL);
		rotate(a, NULL);
	}
	else if (a->head->next->value < a->head->value && \
	a->head->value < a->tail->value)
		swap(a, NULL);
	else if (a->tail->value < a->head->value && \
	a->head->value < a->head->next->value)
		rev_rotate(a, NULL);
	else if (a->tail->value < a->head->next->value && \
	a->head->next->value < a->head->value)
	{
		swap(a, NULL);
		rev_rotate(a, NULL);
	}
	else if (a->head->next->value < a->tail->value && \
	a->tail->value < a->head->value)
		rotate(a, NULL);
}

static void	only_5_input(t_stack *a, t_stack *b, int r)
{
	while (r--)
	{
		if (b->cnt == 2)
			break ;
		if (a->stack->value < a->mid)
			push(a, b, PUSH_B);
		else
			rotate(a, NULL);
	}
	a->stack = a->head;
	only_3_input(a);
	quicksort_in_b(a, b, 2);
}

void		handle_little_input(t_stack *a, t_stack *b, int r)
{
	if (a->cnt == 3)
		only_3_input(a);
	else if (a->cnt == 5)
		only_5_input(a, b, r);
}
