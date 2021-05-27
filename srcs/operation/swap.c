/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:16:48 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:16:49 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *a)
{
	if (a->cnt > 1)
	{
		a->stack = a->stack->next;
		a->stack->prev->next = a->stack->next;
		a->stack->prev->prev = a->stack;
		if (a->stack->next)
			a->stack->next->prev = a->stack->prev;
		a->stack->next = a->stack->prev;
		a->stack->prev = NULL;
		a->head = a->stack;
		if (a->cnt == 2)
			a->tail = a->head->next;
	}
}

void		swap(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		swap_stack(a);
		swap_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		swap_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("sb\n", STDOUT_FILENO);
		swap_stack(b);
	}
}
