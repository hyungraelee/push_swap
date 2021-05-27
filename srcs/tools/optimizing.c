/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:09 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimizing_swap_a(t_stack *a, t_stack *b)
{
	if (b->head && b->head->next)
	{
		if (b->head->value < b->head->next->value)
			swap(a, b);
		else
			swap(a, NULL);
	}
	else
		swap(a, NULL);
}

void	optimizing_rotate_a(t_stack *a, t_stack *b, t_arg *arg, int *r)
{
	if ((*r) > 0 && a->stack->value > arg->pivot[0])
	{
		rotate(a, b);
		arg->cnt_ra++;
		(*r)--;
	}
	else
		rotate(NULL, b);
	arg->cnt_rb++;
}

void	optimizing_swap_b(t_stack *a, t_stack *b)
{
	if (a->head && a->head->next)
	{
		if (a->head->value > a->head->next->value)
			swap(a, b);
		else
			swap(NULL, b);
	}
	else
		swap(NULL, b);
}

void	optimizing_rotate_b(t_stack *a, t_stack *b, t_arg *arg, int *r)
{
	if ((*r) > 0 && b->stack->value <= arg->pivot[1])
	{
		rotate(a, b);
		(*r)--;
		arg->cnt_rb++;
	}
	else
		rotate(a, NULL);
	arg->cnt_ra++;
}
