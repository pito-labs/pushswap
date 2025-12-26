#include "push_swap.h"

static int	max_bits(int max_rank)
{
	int	bits;

	bits = 0;
	while ((max_rank >> bits) != 0)
		bits = bits + 1;
	return (bits);
}

void	ps_sort_radix(t_ps *ps)
{
	int	bit;
	int	bits;
	int	i;
	int	n;

	n = ps->size_a;
	bits = max_bits(n - 1);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < n)
		{
			if (((ps->a[0] >> bit) & 1) == 0)
				op_pb(ps, 1);
			else
				op_ra(ps, 1);
			i = i + 1;
		}
		while (ps->size_b > 0)
			op_pa(ps, 1);
		if (ps->size_b == 0 && ps_is_sorted(ps->a, ps->size_a) != 0)
			return ;
		bit = bit + 1;
	}
}