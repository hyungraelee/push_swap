/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:25:01 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:25:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "checker.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# define BUFFER_SIZE 5000

int		get_next_line(int fd, char **line);

#endif
