/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:38:44 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:38:56 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_ws(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
        || c == '\v' || c == '\f');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int ps_atoi_strict_range(const char *s, int start, int end, int *out)
{
    long    sign;
    long    acc;
    int     i;

    if (!s || start >= end)
        return (1);
    i = start;
    sign = 1;
    if (s[i] == '+' || s[i] == '-')
        if (s[i++] == '-')
            sign = -1;
    if (i >= end)
        return (1);
    acc = 0;
    while (i < end)
    {
        if (!is_digit(s[i]))
            return (1);
        acc = acc * 10 + (s[i++] - '0');
        if ((sign == 1 && acc > INT_MAX)
            || (sign == -1 && (-acc) < INT_MIN))
            return (1);
    }
    *out = (int)(sign * acc);
    return (0);
}

int count_tokens_in_str(const char *s)
{
    int i;
    int count;

    if (!s)
        return (0);
    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] && is_ws(s[i]))
            i++;
        if (!s[i])
            break ;
        count++;
        while (s[i] && !is_ws(s[i]))
            i++;
    }
    return (count);
}

int next_token(const char *s, int *i, int *start, int *end)
{
    while (s[*i] && is_ws(s[*i]))
        *i = *i + 1;
    if (s[*i] == '\0')
        return (0);
    *start = *i;
    while (s[*i] && !is_ws(s[*i]))
        *i = *i + 1;
    *end = *i;
    return (1);
}
