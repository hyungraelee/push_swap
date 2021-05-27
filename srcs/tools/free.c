/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:16:55 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:16:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	while (a->stack)
	{
		if (a->stack->next)
		{
			a->stack = a->stack->next;
			free(a->stack->prev);
		}
		else
		{
			free(a->stack);
			break ;
		}
	}
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}
