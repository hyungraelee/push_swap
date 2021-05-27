/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:08 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:09 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_b_sorted(t_stack *b, int r)
{
	if (b->cnt == 0)
		return (1);
	while (r-- > 1)
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
