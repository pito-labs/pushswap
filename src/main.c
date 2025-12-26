#include "push_swap.h"

static void	ps_init(t_ps *ps, int *rank, int n)
{
	ps->a = rank;
	ps->b = (int *)malloc(sizeof(int) * n);
	ps->size_a = n;
	ps->size_b = 0;
	ps->cap = n;
	if (ps->b == 0)
	{
		free(ps->a);
		ps_error_exit();
	}
}

int	main(int argc, char **argv)
{
	int	*vals;
	int	*rank;
	int	n;
	t_ps	ps;

	vals = 0;
	rank = 0;
	n = 0;
	if (ps_parse(argc, argv, &vals, &n) != 0)
		ps_error_exit();
	if (argc <= 1)
		return (0);
	if (n <= 1)
	{
		free(vals);
		return (0);
	}
	if (ps_compress(vals, n, &rank) != 0)
	{
		free(vals);
		ps_error_exit();
	}
	free(vals);
	if (ps_is_sorted(rank, n) != 0)
	{
		free(rank);
		return (0);
	}
	ps_init(&ps, rank, n);
	ps_sort(&ps);
	free(ps.a);
	free(ps.b);
	return (0);
}