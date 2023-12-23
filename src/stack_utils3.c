/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:02 by skarim            #+#    #+#             */
/*   Updated: 2023/12/23 12:19:29 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}

t_stack_node	*find_cheapest(t_stack_node *b)
{
	while (b)
	{
		if (b->cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}

void	finish_moving(t_stack_node **a, t_stack_node **b,
t_stack_node *cheapest_node)
{
	while (cheapest_node != *b)
	{
		if (cheapest_node->above_median)
			rb(b);
		else
			rrb(b);
	}
	while (cheapest_node->target_node != *a)
	{
		if (cheapest_node->target_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rr(a, b);
	else if (cheapest_node->above_median == false
		&& cheapest_node->target_node->above_median == false)
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rrr(a, b);
	finish_moving(a, b, cheapest_node);
	pa(a, b);
}
