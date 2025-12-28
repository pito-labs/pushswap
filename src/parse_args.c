/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:39:38 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:44:42 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  has_duplicates(const int *vals, int n)
{
    int *copy;
    int i;

    copy = (int *)malloc(sizeof(int) * n);
    if (!copy)
        return (1);
    ps_intcpy(copy, vals, n);
    ps_quicksort_int(copy, 0, n - 1);
    i = 0;
    while (i + 1 < n)
    {
        if (copy[i] == copy[i + 1])
        {
            free(copy);
            return (1);
        }
        i++;
    }
    free(copy);
    return (0);
}

/* Helper for ps_parse: calculates total allocation size */
static int  get_total_count(int argc, char **argv)
{
    int total;
    int i;

    total = 0;
    i = 1;
    while (i < argc)
    {
        total += count_tokens_in_str(argv[i]);
        i++;
    }
    return (total);
}

/* Helper for ps_parse: parses one string argument into vals array */
static int  parse_arg_string(char *s, int *vals, int *k)
{
    int j;
    int start;
    int end;
    int val;

    j = 0;
    while (next_token(s, &j, &start, &end))
    {
        if (ps_atoi_strict_range(s, start, end, &val) != 0)
            return (1);
        vals[*k] = val;
        *k = *k + 1;
    }
    return (0);
}

int ps_parse(int argc, char **argv, int **out_vals, int *out_n)
{
    int *vals;
    int i;
    int k;

    *out_vals = 0;
    *out_n = 0;
    if (argc <= 1)
        return (0);
    *out_n = get_total_count(argc, argv);
    if (*out_n == 0)
        return (1);
    vals = (int *)malloc(sizeof(int) * (*out_n));
    if (!vals)
        return (1);
    i = 1;
    k = 0;
    while (i < argc)
        if (parse_arg_string(argv[i++], vals, &k))
            return (free(vals), 1);
    if (has_duplicates(vals, *out_n))
        return (free(vals), 1);
    *out_vals = vals;
    return (0);
}
