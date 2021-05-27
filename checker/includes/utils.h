#ifndef UTILS_H
# define UTILS_H

# include "checker.h"

void	*ft_memcpy(void *dest, const void *src, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(char *str);

#endif
