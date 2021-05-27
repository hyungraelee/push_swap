/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_3_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:04 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:05 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	type1(t_stack *a, t_stack *b)
{
	optimizing_swap_b(a, b);
	rotate(NULL, b);
	optimizing_swap_b(a, b);
	rev_rotate(NULL, b);
	optimizing_swap_b(a, b);
}

static void	type2(t_stack *a, t_stack *b)
{
	optimizing_swap_b(a, b);
	rotate(NULL, b);
	optimizing_swap_b(a, b);
	rev_rotate(NULL, b);
}

static void	type3(t_stack *a, t_stack *b)
{
	rotate(NULL, b);
	optimizing_swap_b(a, b);
	rev_rotate(NULL, b);
	optimizing_swap_b(a, b);
}

static void	type4(t_stack *a, t_stack *b)
{
	rotate(NULL, b);
	optimizing_swap_b(a, b);
	rev_rotate(NULL, b);
}

void		handle_3_in_b(t_stack *a, t_stack *b)
{
	if (b->stack->value < b->stack->next->value && \
	b->stack->next->value < b->stack->next->next->value)
		type1(a, b);
	else if (b->stack->value < b->stack->next->next->value && \
	b->stack->next->next->value < b->stack->next->value)
		type2(a, b);
	else if (b->stack->next->value < b->stack->value && \
	b->stack->value < b->stack->next->next->value)
		type3(a, b);
	else if (b->stack->next->next->value < b->stack->value && \
	b->stack->value < b->stack->next->value)
		optimizing_swap_b(a, b);
	else if (b->stack->next->value < b->stack->next->next->value && \
	b->stack->next->next->value < b->stack->value)
		type4(a, b);
}
