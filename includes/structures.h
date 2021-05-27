/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:29:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 17:36:25 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "push_swap.h"

typedef struct s_stack		t_stack;
typedef struct s_element	t_element;

struct s_stack
{
	t_element	*stack;
	t_element	*head;
	t_element	*tail;
	int			cnt;
	int			mid;
};

struct s_element
{
	int		value;
	t_element	*next;
	t_element	*prev;
};

#endif
