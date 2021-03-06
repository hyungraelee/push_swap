/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:16:58 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:16:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
