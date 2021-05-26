#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *s);

#endif
