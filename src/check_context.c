/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_context.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:03:29 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:13 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_context2(char *str)
{
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (is_digit(*(str)))
		{
			while (is_digit(*(str)))
				str++;
			if ((*str == '-' || *str == '+'))
				return (1);
		}
		if (*str)
			str++;
	}
	return (0);
}

int	check_context1(char *str)
{
	int		sign;
	int		check;
	int		not_num;
	int		has_digit;
	char	*origin_str;

	origin_str = str;
	sign = 0;
	not_num = 0;
	has_digit = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			sign++;
		else if (is_digit(*str))
			has_digit = 1;
		else if (!(*str == 32))
			not_num++;
		str++;
	}
	check = check_context2(origin_str);
	if (check || sign > 1 || not_num > 0 || !has_digit)
		return (1);
	return (0);
}

int	check_dup_num(t_list *lst, int n)
{
	while (lst)
	{
		if (lst->num == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	check_found_num(t_stack *st, int found_num)
{
	if (!found_num)
		free_and_error(st);
}
