/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:32:54 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:22 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	node_count(t_list *a)
{
	int		count;
	t_list	*current;

	count = 0;
	current = a;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	set_index2(int len, t_list *head, t_list *point)
{
	int		i;
	int		count;
	t_list	*current;

	i = 0;
	count = 0;
	current = head;
	while (i < len)
	{
		if (point->num > current->num)
			count++;
		current = current->next;
		i++;
	}
	return (count);
}

void	set_index1(t_list **a)
{
	int		len;
	int		i;
	int		count;
	t_list	*head;
	t_list	*point;

	i = 0;
	len = node_count(*a);
	head = *a;
	point = head;
	while (i < len)
	{
		count = set_index2(len, head, point);
		point->index = count;
		point = point->next;
		i++;
	}
}
