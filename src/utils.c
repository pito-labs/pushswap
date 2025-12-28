/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:20:03 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 14:20:04 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s != 0 && s[len] != '\0')
		len = len + 1;
	return (len);
}

void	ps_putstr_fd(const char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ps_strlen(s));
}

void	ps_error_exit(void)
{
	ps_putstr_fd("Error\n", 2);
	exit(1);
}

int	ps_is_sorted(const int *arr, int n)
{
	int	i;

	if (arr == 0)
		return (1);
	i = 0;
	while (i + 1 < n)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i = i + 1;
	}
	return (1);
}

void	ps_intcpy(int *dst, const int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i = i + 1;
	}
}

