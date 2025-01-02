/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:16:15 by euleow            #+#    #+#             */
/*   Updated: 2025/01/02 18:09:12 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_INT  2147483647
# define MIN_INT  -2147483648

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list		*a;
	t_list		*b;
}	t_stack;

void		print_error(void);
void		free_and_error(t_stack *st);

t_list		*creat_newnode(int n);
void		push_stack(t_list **a, int num);
void		split_list(t_stack *st, t_list **a, char *str);

int			check_context1(char *str);
int			check_context2(char *str);
int			check_dup_num(t_list *lst, int n);
void		check_found_num(t_stack *st, int found_num);

long		ft_atol(char *str);

void		check_parser(t_stack *st, int ac, char *av[]);
int			num_to_push(t_list **a, char *str, int count);

int			node_count(t_list *a);

t_list		*last_node(t_list *list);

void		swap_a(t_list **a, int print);
void		swap_b(t_list **b, int print);
void		swap_ab(t_list **a, t_list **b);
void		push_a(t_list **a, t_list **b);
void		push_b(t_list **a, t_list **b);
void		rotate_a(t_list **a);
void		rotate_b(t_list **b);
void		rotate_ra(t_list	**a);
void		rotate_rb(t_list **b);

void		set_index1(t_list **a);
int			set_index2(int len, t_list *head, t_list *point);

void		sort2(t_list **a);
void		sort3(t_list **a);
void		sort4(t_list **a, t_list **b, int len);
void		sort5(t_list **a, t_list **b, int len);

int			list_sorted(t_list *list);
void		free_list(t_list **list);
void		butterfly_sort(t_list **a, t_list **b, int len);
void		push_to_a(t_list **a, t_list **b);
#endif
