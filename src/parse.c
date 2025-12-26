#include "push_swap.h"

static int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* parse integer from s[start..end-1] */
int	ps_atoi_strict_range(const char *s, int start, int end, int *out)
{
	long	sign;
	long	acc;
	int		i;

	if (s == 0 || start >= end)
		return (1);
	i = start;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i = i + 1;
	}
	if (i >= end)
		return (1);
	acc = 0;
	while (i < end)
	{
		if (is_digit(s[i]) == 0)
			return (1);
		acc = acc * 10 + (s[i] - '0');
		if (sign == 1 && acc > INT_MAX)
			return (1);
		if (sign == -1 && (-acc) < INT_MIN)
			return (1);
		i = i + 1;
	}
	*out = (int)(sign * acc);
	return (0);
}

static int	count_tokens_in_str(const char *s)
{
	int	i;
	int	count;

	if (s == 0)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && is_ws(s[i]) != 0)
			i = i + 1;
		if (s[i] == '\0')
			break ;
		count = count + 1;
		while (s[i] != '\0' && is_ws(s[i]) == 0)
			i = i + 1;
	}
	return (count);
}

static int	next_token(const char *s, int *i, int *start, int *end)
{
	while (s[*i] != '\0' && is_ws(s[*i]) != 0)
		*i = *i + 1;
	if (s[*i] == '\0')
		return (0);
	*start = *i;
	while (s[*i] != '\0' && is_ws(s[*i]) == 0)
		*i = *i + 1;
	*end = *i;
	return (1);
}

static int	has_duplicates(const int *vals, int n)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * n);
	if (copy == 0)
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
		i = i + 1;
	}
	free(copy);
	return (0);
}

int	ps_parse(int argc, char **argv, int **out_vals, int *out_n)
{
	int	total;
	int	i;
	int	j;
	int	start;
	int	end;
	int	k;
	int	val;
	int	*vals;

	*out_vals = 0;
	*out_n = 0;
	if (argc <= 1)
		return (0);
	total = 0;
	i = 1;
	while (i < argc)
	{
		total = total + count_tokens_in_str(argv[i]);
		i = i + 1;
	}
	if (total == 0)
		return (1);
	vals = (int *)malloc(sizeof(int) * total);
	if (vals == 0)
		return (1);
	k = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (next_token(argv[i], &j, &start, &end) != 0)
		{
			if (ps_atoi_strict_range(argv[i], start, end, &val) != 0)
			{
				free(vals);
				return (1);
			}
			vals[k] = val;
			k = k + 1;
		}
		i = i + 1;
	}
	if (has_duplicates(vals, total) != 0)
	{
		free(vals);
		return (1);
	}
	*out_vals = vals;
	*out_n = total;
	return (0);
}