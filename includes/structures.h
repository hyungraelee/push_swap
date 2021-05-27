/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:29:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:15:06 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "push_swap.h"

typedef struct s_stack		t_stack;
typedef struct s_element	t_element;
typedef struct s_arg		t_arg;

struct	s_stack
{
	t_element	*stack;
	t_element	*head;
	t_element	*tail;
	int			cnt;
	int			mid;
};

struct	s_element
{
	int			value;
	t_element	*next;
	t_element	*prev;
};

struct	s_arg
{
	int	pivot[2];
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_push;
};

#endif
