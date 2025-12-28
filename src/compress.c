/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:32:15 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:49:37 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper: Copy src array to dst */
static void copy_array(int *dst, const int *src, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        dst[i] = src[i];
        i++;
    }
}

/* Helper: Calculate ranks based on sorted array */
static void fill_ranks(int *rank, const int *vals, const int *sorted, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        rank[i] = ps_lower_bound(sorted, n, vals[i]);
        i++;
    }
}

int ps_compress(const int *vals, int n, int **out_rank)
{
    int *sorted;
    int *rank;

    *out_rank = 0;
    sorted = (int *)malloc(sizeof(int) * n);
    rank = (int *)malloc(sizeof(int) * n);
    if (!sorted || !rank)
    {
        free(sorted);
        free(rank);
        return (1);
    }
    copy_array(sorted, vals, n);
    if (n > 1)
        ps_quicksort_int(sorted, 0, n - 1);
    fill_ranks(rank, vals, sorted, n);
    free(sorted);
    *out_rank = rank;
    return (0);
}
