/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:29:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/16 16:48:20 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "push_swap.h"

typedef struct s_stack	t_stack;

struct s_stack
{
	int		value;
	t_stack	*next;
	t_stack	*prev;
};

#endif
