/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:14:55 by skarim            #+#    #+#             */
/*   Updated: 2023/12/21 21:53:15 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (b)
	{
		if (b->above_median)
			b->push_cost = b->index;
		else
			b->push_cost = len_b - b->index;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - b->target_node->index;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*tmp;
	int				min;

	min = INT_MAX;
	while (b)
	{
		if (b->push_cost < min)
		{
			min = b->push_cost;
			tmp = b;
		}
		b = b->next;
	}
	tmp->cheapest = true;
}
