/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:53:52 by macbookpro2       #+#    #+#             */
/*   Updated: 2025/12/28 13:55:17 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	cap;
}	t_ps;

/* parse (parse_args.c & parse_utils.c) */
int		ps_parse(int argc, char **argv, int **out_vals, int *out_n);
int		is_ws(char c);
int		is_digit(char c);
int		ps_atoi_strict_range(const char *s, int start, int end, int *out);
int		count_tokens_in_str(const char *s);
int		next_token(const char *s, int *i, int *start, int *end);

/* compress */
int		ps_compress(const int *vals, int n, int **out_rank);

/* sort */
void	ps_sort(t_ps *ps);

/* op_utils (shared helper functions) */
void	shift_left(int *arr, int n);
void	shift_right(int *arr, int n);
void	put_op(const char *s, int print);

/* operations (print=1 prints op, print=0 is silent) */
void	op_sa(t_ps *ps, int print);
void	op_sb(t_ps *ps, int print);
void	op_ss(t_ps *ps, int print);
void	op_pa(t_ps *ps, int print);
void	op_pb(t_ps *ps, int print);
void	op_ra(t_ps *ps, int print);
void	op_rb(t_ps *ps, int print);
void	op_rr(t_ps *ps, int print);
void	op_rra(t_ps *ps, int print);
void	op_rrb(t_ps *ps, int print);
void	op_rrr(t_ps *ps, int print);

/* small sorts */
void	ps_sort_2(t_ps *ps);
void	ps_sort_3(t_ps *ps);
void	ps_sort_4_5(t_ps *ps);

/* radix */
void	ps_sort_radix(t_ps *ps);

/* utils */
void	ps_putstr_fd(const char *s, int fd);
int		ps_strlen(const char *s);
int		ps_is_sorted(const int *arr, int n);
void	ps_error_exit(void);

/* array/sort helpers */
void	ps_intcpy(int *dst, const int *src, int n);
void	ps_quicksort_int(int *arr, int left, int right);
int		ps_lower_bound(const int *arr, int n, int target);

#endif