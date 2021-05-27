/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:25:26 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:25:27 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	set_src_stack(t_stack *src)
{
	if (src->cnt == 2)
	{
		src->head = src->stack;
		src->head->prev = NULL;
		src->tail = NULL;
	}
	else if (src->cnt > 2)
	{
		src->head = src->stack;
		src->head->prev = NULL;
	}
	else
	{
		src->head = NULL;
		src->tail = NULL;
		src->stack = NULL;
	}
}

static void	handle_des_empty(t_stack *src, t_stack *des)
{
	des->stack = src->head;
	des->head = des->stack;
	des->head->prev = NULL;
	des->head->next = NULL;
	set_src_stack(src);
	des->tail = NULL;
}

static void	handle_des_exist(t_stack *src, t_stack *des)
{
	des->head = src->head;
	des->head->next = des->stack;
	des->stack->prev = des->head;
	des->stack = des->head;
	set_src_stack(src);
	if (des->cnt == 1)
		des->tail = des->head->next;
}

static void	push_stack(t_stack *src, t_stack *des)
{
	if (src->cnt > 0)
	{
		src->stack = src->stack->next;
		if (des->cnt == 0)
			handle_des_empty(src, des);
		else if (des->cnt >= 1)
			handle_des_exist(src, des);
		des->cnt++;
		src->cnt--;
	}
}

void		push(t_stack *a, t_stack *b, int type)
{
	if (type == PUSH_A)
		push_stack(b, a);
	else if (type == PUSH_B)
		push_stack(a, b);
}
