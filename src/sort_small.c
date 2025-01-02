/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:53:29 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:00 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort2(t_list **a)
{
	t_list	*temp;

	temp = *a;
	if (temp->num > temp->next->num)
		swap_a(a, 1);
}

static void	sort3_logic(t_list **a, int n1, int n2, int n3)
{
	if (!list_sorted(*a))
		return ;
	if (n1 > n2 && n1 < n3)
		swap_a(a, 1);
	else if (n1 < n2 && n1 < n3)
	{
		rotate_ra(a);
		swap_a(a, 1);
	}
	else if (n1 < n2 && n1 > n3)
		rotate_ra(a);
	else if (n1 > n2 && n1 > n3)
	{
		if (n2 > n3)
		{
			rotate_a(a);
			swap_a(a, 1);
		}
		else
		{
			rotate_ra(a);
			rotate_ra(a);
		}
	}
}

void	sort3(t_list **a)
{
	t_list	*n;
	int		n1;
	int		n2;
	int		n3;

	n = *a;
	n1 = n->index;
	n2 = n->next->index;
	n3 = n->next->next->index;
	sort3_logic(a, n1, n2, n3);
}

void	sort4(t_list **a, t_list **b, int len)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		p;

	temp_a = *a;
	p = 0;
	while ((len - p) > 3)
	{
		if (temp_a->index == 0)
		{
			push_b(a, b);
			p++;
		}
		else
			rotate_ra(a);
		temp_a = *a;
	}
	sort3(a);
	temp_b = *b;
	push_a(a, b);
}

void	sort5(t_list **a, t_list **b, int len)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		p;

	temp_a = *a;
	p = 0;
	while ((len - p) > 3)
	{
		if (temp_a->index == 0 || temp_a->index == 1)
		{
			push_b(a, b);
			p++;
		}
		else
			rotate_ra(a);
		temp_a = *a;
	}
	sort3(a);
	temp_b = *b;
	if (temp_b->index < temp_b->next->index)
		swap_b(b, 1);
	push_a(a, b);
	push_a(a, b);
}
