/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:32:38 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:31:18 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ps_quicksort_int(int *arr, int left, int right)
{
	int	l;
	int	r;
	int	pivot;

	l = left;
	r = right;
	pivot = arr[(left + right) / 2];
	while (l <= r)
	{
		while (arr[l] < pivot)
			l = l + 1;
		while (arr[r] > pivot)
			r = r - 1;
		if (l <= r)
		{
			swap_int(&arr[l], &arr[r]);
			l = l + 1;
			r = r - 1;
		}
	}
	if (left < r)
		ps_quicksort_int(arr, left, r);
	if (l < right)
		ps_quicksort_int(arr, l, right);
}

int	ps_lower_bound(const int *arr, int n, int target)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n;
	while (lo < hi)
	{
		mid = lo + (hi - lo) / 2;
		if (arr[mid] < target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return (lo);
}
