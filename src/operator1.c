/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:53:36 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:20 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **a, int print)
{
	t_list	*first;
	t_list	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **b, int print)
{
	t_list	*first;
	t_list	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	swap_ab(t_list **a, t_list **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	write(1, "ss\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *a;
	head_b = *b;
	*b = head_b->next;
	head_b->next = head_a;
	*a = head_b;
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*head_a;

	head_a = *a;
	*a = head_a->next;
	head_a->next = *b;
	*b = head_a;
	write(1, "pb\n", 3);
}
