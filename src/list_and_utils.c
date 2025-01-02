/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_and_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:54:12 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:18 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*temp;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*list = (NULL);
}

int	list_sorted(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp && temp->next)
	{
		if (temp->index > temp->next->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_and_error(t_stack *st)
{
	if (st->a)
		free_list(&st->a);
	if (st->b)
		free_list(&st->b);
	free(st);
	print_error();
}
