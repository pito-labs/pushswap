/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:29:31 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:29:34 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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