/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:16:45 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:16:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *a)
{
	if (a->cnt > 1)
	{
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail = a->head;
		a->head = a->tail->next;
		a->head->prev = NULL;
		a->tail->next = NULL;
		a->stack = a->head;
	}
}

void		rotate(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		rotate_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("rb\n", STDOUT_FILENO);
		rotate_stack(b);
	}
}
