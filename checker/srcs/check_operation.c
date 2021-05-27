/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:26:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:26:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_push(char *operation)
{
	return (!ft_strcmp("pa", operation) || !ft_strcmp("pb", operation));
}

int		is_swap(char *operation)
{
	return (!ft_strcmp("sa", operation) || !ft_strcmp("sb", operation) || \
	!ft_strcmp("ss", operation));
}

int		is_rotate(char *operation)
{
	return (!ft_strcmp("ra", operation) || !ft_strcmp("rb", operation) || \
	!ft_strcmp("rr", operation));
}

int		is_rev_rotate(char *operation)
{
	return (!ft_strcmp("rra", operation) || !ft_strcmp("rrb", operation) || \
	!ft_strcmp("rrr", operation));
}
