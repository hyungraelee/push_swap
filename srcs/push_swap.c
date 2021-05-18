#include "push_swap.h"

int	push_swap(t_stack *a, t_stack *b)
{
	while (!is_finish(a, b))
	{
		if (is_a_sorted(a))
		{
			if (is_b_sorted(b))
			{
				while (!is_finish(a, b))
					; //pa
				break ;
			}
			else
			{
				// sort b
			}
		}
		else
		{
			
		}
	}
	// free_all
	return (1);
}
