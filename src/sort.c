#include "push_swap.h"

void	ps_sort(t_ps *ps)
{
	if (ps->size_a <= 1)
		return ;
	if (ps_is_sorted(ps->a, ps->size_a) != 0)
		return ;
	if (ps->size_a == 2)
		ps_sort_2(ps);
	else if (ps->size_a == 3)
		ps_sort_3(ps);
	else if (ps->size_a == 4 || ps->size_a == 5)
		ps_sort_4_5(ps);
	else
		ps_sort_radix(ps);
}