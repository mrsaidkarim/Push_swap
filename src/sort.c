/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:42 by skarim            #+#    #+#             */
/*   Updated: 2023/12/22 21:20:50 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	ft_sort_three(t_stack_node **a)
{
	int				max;
	int				i;
	t_stack_node	*tmp;

	max = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	tmp = *a;
	i = 1;
	while (tmp->value != max)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 1)
		ra(a);
	else if (i == 2)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	ft_sorting(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*small;

	while (ft_stack_len(*a) > 3)
	{
		pb(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_to_a(a, b);
	}
	small = smallest(*a);
	ft_set_index(*a);
	while (*a != small && small->above_median)
		ra(a);
	while (*a != small && !(small->above_median))
		rra(a);
}

void	ft_sort(t_stack_node **a, t_stack_node **b)
{
	if (ft_stack_len(*a) == 2)
		ft_sort_two(a);
	else if (ft_stack_len(*a) == 3)
		ft_sort_three(a);
	else
		ft_sorting(a, b);
}
