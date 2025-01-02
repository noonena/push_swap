/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:53:11 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:05 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*creat_newnode(int n)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = n;
	new->next = NULL;
	return (new);
}

void	push_stack(t_list **a, int num)
{
	t_list			*current;
	static t_list	*lastnode = NULL;

	current = creat_newnode(num);
	if (!current)
		return ;
	if (*a == NULL)
		*a = current;
	else
		lastnode->next = current;
	lastnode = current;
}
