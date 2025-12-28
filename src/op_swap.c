/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:27:31 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:27:33 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_ps *ps, int print)
{
	int	t;

	if (ps->size_a < 2)
		return ;
	t = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = t;
	put_op("sa\n", print);
}

void	op_sb(t_ps *ps, int print)
{
	int	t;

	if (ps->size_b < 2)
		return ;
	t = ps->b[0];
	ps->b[0] = ps->b[1];
	ps->b[1] = t;
	put_op("sb\n", print);
}

void	op_ss(t_ps *ps, int print)
{
	op_sa(ps, 0);
	op_sb(ps, 0);
	put_op("ss\n", print);
}