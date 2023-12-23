/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:04:11 by skarim            #+#    #+#             */
/*   Updated: 2023/12/23 10:50:41 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack_node *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void	ft_set_index(t_stack_node *s)
{
	int	i;
	int	mid;

	if (s == NULL)
		return ;
	i = 0;
	mid = ft_stack_len(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= mid)
			s->above_median = true;
		else
			s->above_median = false;
		i++;
		s = s->next;
	}
}

t_stack_node	*smallest(t_stack_node *a)
{
	int				min;
	t_stack_node	*min_node;

	min = INT_MAX;
	while (a)
	{
		if (a->value <= min)
		{
			min = a->value;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	int				cbv;
	t_stack_node	*closest_bigger;
	t_stack_node	*tmp;

	while (b)
	{
		cbv = INT_MAX;
		tmp = a;
		while (tmp)
		{
			if (b->value < tmp->value && tmp->value <= cbv)
			{
				cbv = tmp->value;
				closest_bigger = tmp;
			}
			tmp = tmp->next;
		}
		if (cbv == INT_MAX)
			closest_bigger = smallest(a);
		b->target_node = closest_bigger;
		b = b->next;
	}
}
