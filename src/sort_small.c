#include "push_swap.h"

void	ps_sort_2(t_ps *ps)
{
	if (ps->size_a == 2 && ps->a[0] > ps->a[1])
		op_sa(ps, 1);
}

void	ps_sort_3(t_ps *ps)
{
	int	x;
	int	y;
	int	z;

	if (ps->size_a != 3)
		return ;
	x = ps->a[0];
	y = ps->a[1];
	z = ps->a[2];
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		op_sa(ps, 1);
	else if (x > y && y > z)
	{
		op_sa(ps, 1);
		op_rra(ps, 1);
	}
	else if (x > y && y < z && x > z)
		op_ra(ps, 1);
	else if (x < y && y > z && x < z)
	{
		op_sa(ps, 1);
		op_ra(ps, 1);
	}
	else if (x < y && y > z && x > z)
		op_rra(ps, 1);
}

static int	pos_of_min(const int *arr, int n)
{
	int	pos;
	int	i;

	pos = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[pos])
			pos = i;
		i = i + 1;
	}
	return (pos);
}

static void	bring_pos_to_top_a(t_ps *ps, int pos)
{
	int	sz;

	sz = ps->size_a;
	while (pos != 0)
	{
		if (pos <= sz / 2)
		{
			op_ra(ps, 1);
			pos = pos - 1;
		}
		else
		{
			op_rra(ps, 1);
			pos = pos + 1;
			if (pos == sz)
				pos = 0;
		}
	}
}

void	ps_sort_4_5(t_ps *ps)
{
	int	push_count;
	int	pos;

	if (ps->size_a != 4 && ps->size_a != 5)
		return ;
	push_count = ps->size_a - 3;
	while (push_count > 0)
	{
		pos = pos_of_min(ps->a, ps->size_a);
		bring_pos_to_top_a(ps, pos);
		op_pb(ps, 1);
		push_count = push_count - 1;
	}
	ps_sort_3(ps);
	while (ps->size_b > 0)
		op_pa(ps, 1);
}