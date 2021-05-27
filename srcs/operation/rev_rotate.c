/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:16:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:16:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack *a)
{
	if (a->cnt > 1)
	{
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->head = a->tail;
		a->tail = a->tail->prev;
		a->head->prev = NULL;
		a->tail->next = NULL;
		a->stack = a->head;
	}
}

void		rev_rotate(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		rev_rotate_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		rev_rotate_stack(b);
	}
}
