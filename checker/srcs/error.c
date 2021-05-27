#include "checker.h"

void	print_err(char *str)
{
	ft_putstr_fd(B_RED, STDOUT_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(C_RESET, STDOUT_FILENO);
	exit(1);
}
