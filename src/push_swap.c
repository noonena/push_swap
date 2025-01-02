/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:54:11 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:04:04 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_sorting_type(t_stack *st, int len)
{
	if (len == 2)
		sort2(&st->a);
	else if (len == 3)
		sort3(&st->a);
	else if (len == 4)
		sort4(&st->a, &st->b, len);
	else if (len <= 5)
		sort5(&st->a, &st->b, len);
	else
		butterfly_sort(&st->a, &st->b, len);
}

int	main(int ac, char *av[])
{
	t_stack	*st;
	int		len;

	if (ac == 1)
		return (0);
	st = NULL;
	st = malloc(sizeof(t_stack));
	check_parser(st, ac, av);
	set_index1(&st->a);
	len = node_count(st->a);
	if (!list_sorted(st->a))
	{
		free_list(&st->a);
		free(st);
		return (0);
	}
	check_sorting_type(st, len);
	free_list(&st->a);
	free_list(&st->b);
	free(st);
}
