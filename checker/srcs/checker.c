/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:26:45 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:26:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_a_sorted(t_stack *a, int r)
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

static void	check_sort(t_stack *a, t_stack *b, int r)
{
	if (is_a_sorted(a, r))
		if (b->stack == NULL)
			print_ok();
		else
			print_ko();
	else
		print_ko();
}

void		checker(t_stack *a, t_stack *b, int r)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		if (is_push(buf))
			push_handler(a, b, buf);
		else if (is_swap(buf))
			swap_handler(a, b, buf);
		else if (is_rotate(buf))
			rotate_handler(a, b, buf);
		else if (is_rev_rotate(buf))
			rev_rotate_handler(a, b, buf);
	}
	if (buf)
		free(buf);
	check_sort(a, b, r);
}
