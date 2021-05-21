/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:29:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 16:41:08 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "push_swap.h"

typedef struct s_a		t_a;
typedef struct s_a		t_b;
typedef struct s_stack	t_stack;

struct s_a
{
	t_stack	*stack;
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;
};

struct s_stack
{
	int		value;
	t_stack	*next;
	t_stack	*prev;
};

#endif
