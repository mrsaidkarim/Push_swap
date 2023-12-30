/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:14:55 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:05:11 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	cost;
	int	tmp;
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (b)
	{
		cost = ft_max(b->target_node->index, b->index);
		tmp = ft_max(len_a - b->target_node->index, len_b - b->index);
		if (tmp < cost)
			cost = tmp;
		tmp = b->target_node->index + (len_b - b->index);
		if (tmp < cost)
			cost = tmp;
		tmp = (len_a - b->target_node->index) + b->index;
		if (tmp < cost)
			cost = tmp;
		b->push_cost = cost;
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
