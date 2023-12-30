/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:02 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:05:14 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

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

int	index_min(int len_a, t_stack_node *cheapest_node, int len_b)
{
	int	opr_r;
	int	opr_rr;
	int	opr_rarrb;
	int	opr_rrarb;

	opr_r = ft_max(cheapest_node->index, cheapest_node->target_node->index);
	opr_rr = ft_max((len_a - cheapest_node->target_node->index),
			(len_b - cheapest_node->index));
	opr_rarrb = cheapest_node->target_node->index
		+ (len_b - cheapest_node->index);
	opr_rrarb = (len_a - cheapest_node->target_node->index)
		+ cheapest_node->index;
	if (opr_r < opr_rr && opr_r < opr_rarrb && opr_r < opr_rrarb)
		return (1);
	else if (opr_rr < opr_r && opr_rr < opr_rarrb && opr_rr < opr_rrarb)
		return (2);
	else if (opr_rarrb < opr_r && opr_rarrb < opr_rr && opr_rarrb < opr_rrarb)
		return (3);
	return (4);
}

void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	int				index;

	cheapest_node = find_cheapest(*b);
	index = index_min(ft_stack_len(*a), cheapest_node, ft_stack_len(*b));
	if (index == 1)
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rr(a, b);
	else if (index == 2)
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rrr(a, b);
	ft_set_index(*a);
	ft_set_index(*b);
	finish_moving(a, b, cheapest_node);
	pa(a, b);
}
