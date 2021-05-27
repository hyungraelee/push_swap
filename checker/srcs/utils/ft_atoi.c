#include "checker.h"

int		ft_atoi(char *str)
{
	long long	res;
	int			sign;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		print_err(ERR_MSG3);
	return ((int)res);
}
