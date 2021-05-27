#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "checker.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# define BUFFER_SIZE 5000

int		get_next_line(int fd, char **line);

#endif
