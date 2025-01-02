/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:53:47 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:09 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	num_to_push(t_list **a, char *str, int count)
{
	char	*temp;
	long	n;
	int		i;

	i = 0;
	temp = malloc(count + 1);
	if (!temp)
		return (0);
	while (i < count)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	n = ft_atol(temp);
	if (check_context1(temp) || check_dup_num(*a, n) \
	|| n < MIN_INT || n > MAX_INT)
	{
		free(temp);
		return (0);
	}
	push_stack(a, n);
	free(temp);
	return (1);
}

void	split_list(t_stack *st, t_list **a, char *str)
{
	int	i;
	int	start;
	int	end;
	int	found_num;

	i = 0;
	start = 0;
	end = 0;
	found_num = 0;
	while (str[i])
	{
		while (str[i] && str[i] == 32)
			i++;
		start = i;
		while (str[i] && str[i] != 32)
			i++;
		end = i;
		if (end > start)
		{
			if (!num_to_push(a, str + start, end - start))
				free_and_error(st);
			found_num = 1;
		}
	}
	check_found_num(st, found_num);
}

void	check_parser(t_stack *st, int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	st->a = NULL;
	st->b = NULL;
	while (av[i])
	{
		if (av[i][0] == '\0' || av[i][j] == '\t')
		{
			free_and_error(st);
		}
		split_list(st, &st->a, av[i]);
		i++;
	}
}
