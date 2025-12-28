/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:28:18 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:28:20 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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