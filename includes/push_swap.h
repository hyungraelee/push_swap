/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:57:44 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 18:27:18 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "structures.h"
# include "utils.h"
# include "tools.h"

# define PUSH_A 1
# define PUSH_B 2

int			push_swap(t_stack *a, t_stack *b, int r);

char		**init_arg(int *argc, char **argv);
void		check_arg(int argc, char **argv);

t_stack		*set_stack(int argc, char **argv);
t_stack		*init_stack(void);
t_element	*init_element(void);

void		handle_little_input(t_stack *a, t_stack *b, int r);

void		quicksort_in_a(t_stack *a, t_stack *b, int r);
void		quicksort_in_b(t_stack *a, t_stack *b, int r);

void		push(t_stack *a, t_stack *b, int type);
void		swap(t_stack *a, t_stack *b);
void		rotate(t_stack *a, t_stack *b);
void		rev_rotate(t_stack *a, t_stack *b);



#endif
