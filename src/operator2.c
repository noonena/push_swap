/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:45:00 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:27 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list	**a)
{
	t_list	*head_a;
	t_list	*head;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	head_a = *a;
	head = head_a->next;
	last = last_node(*a);
	last->next = head_a;
	head_a->next = NULL;
	*a = head;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list	**b)
{
	t_list	*head_b;
	t_list	*head;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	head_b = *b;
	head = head_b->next;
	last = last_node(*b);
	last->next = head_b;
	head_b->next = NULL;
	*b = head;
	write(1, "rb\n", 3);
}

void	rotate_ra(t_list	**a)
{
	t_list	*head_a;
	t_list	*head;
	t_list	*last;
	t_list	*b_last;
	int		len;

	if (!a || !(*a) || !(*a)->next)
		return ;
	b_last = *a;
	head_a = *a;
	len = node_count(*a);
	while (len-- > 2)
		b_last = b_last->next;
	last = last_node(*a);
	head = last;
	last->next = head_a;
	b_last->next = NULL;
	*a = head;
	write(1, "rra\n", 4);
}

void	rotate_rb(t_list	**b)
{
	t_list	*head_b;
	t_list	*head;
	t_list	*last;
	t_list	*a_last;
	int		len;

	if (!b || !*b || !(*b)->next)
		return ;
	a_last = *b;
	head_b = *b;
	len = node_count(*b);
	while (len-- > 2)
		a_last = a_last->next;
	last = last_node(*b);
	head = last;
	last->next = head_b;
	a_last->next = NULL;
	*b = head;
	write(1, "rrb\n", 4);
}
