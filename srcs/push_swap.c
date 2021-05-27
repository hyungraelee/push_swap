/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:19 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 00:15:55 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *a, t_stack *b, int r)
{
	if (a->cnt == 3 || a->cnt == 5)
		handle_little_input(a, b, r);
	else
		quicksort_in_a(a, b, r);
	free_all(a, b);
	return (1);
}
