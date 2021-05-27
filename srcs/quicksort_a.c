/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:20 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 01:57:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_in_a(t_stack *a, t_arg *arg, int *r)
{
	rotate(a, NULL);
	(*r)--;
	arg->cnt_ra++;
}

static void	push_in_a(t_stack *a, t_stack *b, t_arg *arg, int *r)
{
	push(a, b, PUSH_B);
	(*r)--;
	arg->cnt_push++;
}

void		quicksort_in_a(t_stack *a, t_stack *b, int r)
{
	t_arg	arg;

	if (escape_condition_in_a(a, b, r))
		return ;
	get_pivot(a, r, arg.pivot);
	init_cnt(&arg);
	while (r > 0)
	{
		if (a->stack->value > arg.pivot[0])
		{
			if (is_whole_big(a, r, arg.pivot[0]))
				break ;
			rotate_in_a(a, &arg, &r);
		}
		else
		{
			push_in_a(a, b, &arg, &r);
			if (b->head->value > arg.pivot[1])
				optimizing_rotate_a(a, b, &arg, &r);
		}
	}
	reset_rotate(a, b, arg);
	quicksort_in_a(a, b, arg.cnt_ra + r);
	quicksort_in_b(a, b, arg.cnt_rb);
	quicksort_in_b(a, b, arg.cnt_push - arg.cnt_rb);
}
