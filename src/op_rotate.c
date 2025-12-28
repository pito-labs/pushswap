/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:29:03 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:29:05 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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