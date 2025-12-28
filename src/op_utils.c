/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:26:40 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 14:07:49 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_left(int *arr, int n)
{
	int	i;

	if (n <= 1)
		return ;
	i = 0;
	while (i + 1 < n)
	{
		arr[i] = arr[i + 1];
		i = i + 1;
	}
}

void	shift_right(int *arr, int n)
{
	int	i;

	if (n <= 1)
		return ;
	i = n - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i = i - 1;
	}
}

void	put_op(const char *s, int print)
{
	if (print != 0)
		ps_putstr_fd(s, 1);
}
