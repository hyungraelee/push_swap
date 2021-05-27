/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:11 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_rotate(t_stack *a, t_stack *b, t_arg arg)
{
	if (arg.cnt_rb > arg.cnt_ra)
	{
		while (arg.cnt_rb-- != arg.cnt_ra)
			rev_rotate(NULL, b);
		while (arg.cnt_ra--)
			rev_rotate(a, b);
	}
	else
	{
		while (arg.cnt_ra-- != arg.cnt_rb)
			rev_rotate(a, NULL);
		while (arg.cnt_rb--)
			rev_rotate(a, b);
	}
}
