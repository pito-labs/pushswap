#include "push_swap.h"

static void	shift_left(int *arr, int n)
{
	int	i;

	if (n <= 1)
		return ;
	i = 0;
	while (i + 1 < n)
	{
		arr[i] = arr[i + 1];
		i = i + 1;
	}
}

static void	shift_right(int *arr, int n)
{
	int	i;

	if (n <= 1)
		return ;
	i = n - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i = i - 1;
	}
}

static void	put_op(const char *s, int print)
{
	if (print != 0)
		ps_putstr_fd(s, 1);
}

void	op_sa(t_ps *ps, int print)
{
	int	t;

	if (ps->size_a < 2)
		return ;
	t = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = t;
	put_op("sa\n", print);
}

void	op_sb(t_ps *ps, int print)
{
	int	t;

	if (ps->size_b < 2)
		return ;
	t = ps->b[0];
	ps->b[0] = ps->b[1];
	ps->b[1] = t;
	put_op("sb\n", print);
}

void	op_ss(t_ps *ps, int print)
{
	op_sa(ps, 0);
	op_sb(ps, 0);
	put_op("ss\n", print);
}

void	op_pa(t_ps *ps, int print)
{
	int	top;

	if (ps->size_b <= 0)
		return ;
	top = ps->b[0];
	shift_left(ps->b, ps->size_b);
	ps->size_b = ps->size_b - 1;
	ps->size_a = ps->size_a + 1;
	shift_right(ps->a, ps->size_a);
	ps->a[0] = top;
	put_op("pa\n", print);
}

void	op_pb(t_ps *ps, int print)
{
	int	top;

	if (ps->size_a <= 0)
		return ;
	top = ps->a[0];
	shift_left(ps->a, ps->size_a);
	ps->size_a = ps->size_a - 1;
	ps->size_b = ps->size_b + 1;
	shift_right(ps->b, ps->size_b);
	ps->b[0] = top;
	put_op("pb\n", print);
}

void	op_ra(t_ps *ps, int print)
{
	int	top;

	if (ps->size_a < 2)
		return ;
	top = ps->a[0];
	shift_left(ps->a, ps->size_a);
	ps->a[ps->size_a - 1] = top;
	put_op("ra\n", print);
}

void	op_rb(t_ps *ps, int print)
{
	int	top;

	if (ps->size_b < 2)
		return ;
	top = ps->b[0];
	shift_left(ps->b, ps->size_b);
	ps->b[ps->size_b - 1] = top;
	put_op("rb\n", print);
}

void	op_rr(t_ps *ps, int print)
{
	op_ra(ps, 0);
	op_rb(ps, 0);
	put_op("rr\n", print);
}

void	op_rra(t_ps *ps, int print)
{
	int	bot;

	if (ps->size_a < 2)
		return ;
	bot = ps->a[ps->size_a - 1];
	shift_right(ps->a, ps->size_a);
	ps->a[0] = bot;
	put_op("rra\n", print);
}

void	op_rrb(t_ps *ps, int print)
{
	int	bot;

	if (ps->size_b < 2)
		return ;
	bot = ps->b[ps->size_b - 1];
	shift_right(ps->b, ps->size_b);
	ps->b[0] = bot;
	put_op("rrb\n", print);
}

void	op_rrr(t_ps *ps, int print)
{
	op_rra(ps, 0);
	op_rrb(ps, 0);
	put_op("rrr\n", print);
}