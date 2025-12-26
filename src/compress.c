#include "push_swap.h"

int	ps_compress(const int *vals, int n, int **out_rank)
{
	int	*sorted;
	int	*rank;
	int	i;
	int	pos;

	*out_rank = 0;
	sorted = (int *)malloc(sizeof(int) * n);
	rank = (int *)malloc(sizeof(int) * n);
	if (sorted == 0 || rank == 0)
	{
		free(sorted);
		free(rank);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		sorted[i] = vals[i];
		i = i + 1;
	}
	if (n > 1)
		ps_quicksort_int(sorted, 0, n - 1);
	i = 0;
	while (i < n)
	{
		pos = ps_lower_bound(sorted, n, vals[i]);
		rank[i] = pos;
		i = i + 1;
	}
	free(sorted);
	*out_rank = rank;
	return (0);
}