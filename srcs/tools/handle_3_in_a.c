/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_3_in_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:02 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:03 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	type1(t_stack *a, t_stack *b)
{
	rotate(a, NULL);
	optimizing_swap_a(a, b);
	rev_rotate(a, NULL);
}

static void	type2(t_stack *a, t_stack *b)
{
	rotate(a, NULL);
	optimizing_swap_a(a, b);
	rev_rotate(a, NULL);
	optimizing_swap_a(a, b);
}

static void	type3(t_stack *a, t_stack *b)
{
	optimizing_swap_a(a, b);
	rotate(a, NULL);
	optimizing_swap_a(a, b);
	rev_rotate(a, NULL);
}

static void	type4(t_stack *a, t_stack *b)
{
	optimizing_swap_a(a, b);
	rotate(a, NULL);
	optimizing_swap_a(a, b);
	rev_rotate(a, NULL);
	optimizing_swap_a(a, b);
}

void		handle_3_in_a(t_stack *a, t_stack *b)
{
	if (a->stack->value < a->stack->next->next->value && \
	a->stack->next->next->value < a->stack->next->value)
		type1(a, b);
	else if (a->stack->next->value < a->stack->value && \
	a->stack->value < a->stack->next->next->value)
		optimizing_swap_a(a, b);
	else if (a->stack->next->next->value < a->stack->value && \
	a->stack->value < a->stack->next->value)
		type2(a, b);
	else if (a->stack->next->value < a->stack->next->next->value && \
	a->stack->next->next->value < a->stack->value)
		type3(a, b);
	else if (a->stack->next->next->value < a->stack->next->value && \
	a->stack->next->value < a->stack->value)
		type4(a, b);
}
