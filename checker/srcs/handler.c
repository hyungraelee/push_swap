/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:25:47 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:26:53 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("pa", operation))
		push(a, b, PUSH_A);
	else if (!ft_strcmp("pb", operation))
		push(a, b, PUSH_B);
}

void	swap_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("sa", operation))
		swap(a, NULL);
	else if (!ft_strcmp("sb", operation))
		swap(NULL, b);
	else if (!ft_strcmp("ss", operation))
		swap(a, b);
}

void	rotate_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("ra", operation))
		rotate(a, NULL);
	else if (!ft_strcmp("rb", operation))
		rotate(NULL, b);
	else if (!ft_strcmp("rr", operation))
		rotate(a, b);
}

void	rev_rotate_handler(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp("rra", operation))
		rev_rotate(a, NULL);
	else if (!ft_strcmp("rrb", operation))
		rev_rotate(NULL, b);
	else if (!ft_strcmp("rrr", operation))
		rev_rotate(a, b);
}
