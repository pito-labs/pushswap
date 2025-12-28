/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:32:21 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:53:09 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ps_init(t_ps *ps, int *rank, int n)
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

int main(int argc, char **argv)
{
    t_ps    ps;
    int     *vals;
    int     *rank;
    int     n;

    if (ps_parse(argc, argv, &vals, &n))
        ps_error_exit();
    if (n == 0)
        return (0);
    if (ps_compress(vals, n, &rank))
        return (free(vals), ps_error_exit(), 1);
    free(vals);
    if (n == 1 || ps_is_sorted(rank, n))
        return (free(rank), 0);
    ps_init(&ps, rank, n);
    ps_sort(&ps);
    free(ps.a);
    free(ps.b);
    return (0);
}
