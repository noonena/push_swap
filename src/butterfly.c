/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:57 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:11 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_list *list, int *len)
{
	int	max;

	max = -1;
	while (list)
	{
		if (list->index > max)
			max = list->index;
		list = list->next;
		(*len)++;
	}
	return (max);
}

int	find_index_of_max(t_list *list, int max)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->index == max)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}

void	push_to_a(t_list **a, t_list **b)
{
	int		length;
	int		max;
	int		index;
	int		j;
	t_list	*temp_b;

	length = 0;
	temp_b = *b;
	max = find_max(temp_b, &length);
	index = find_index_of_max(temp_b, max);
	if (index > length / 2)
	{
		if (temp_b->index == max)
			push_a(a, b);
		else
			rotate_rb(b);
	}
	else
	{
		if (temp_b->index == max)
			push_a(a, b);
		else
			rotate_b(b);
	}
}

void	butterfly_sort(t_list **a, t_list **b, int len)
{
	int	i;
	int	mul_num;

	i = 0;
	mul_num = 15;
	if (len > 100)
		mul_num = 30;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			push_b(a, b);
			rotate_b(b);
			i++;
		}
		else if ((*a)->index < (i + mul_num))
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
	while (*b)
		push_to_a(a, b);
}
