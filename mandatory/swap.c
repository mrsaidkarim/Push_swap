/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:23:21 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:05:17 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	swap(t_stack_node **s)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	if (*s && (*s)->next)
	{
		tmp1 = *s;
		tmp2 = (*s)->next;
		tmp1->next = tmp2->next;
		tmp1->prev = tmp2;
		tmp2->next = tmp1;
		tmp2->prev = NULL;
		if (tmp1->next)
			tmp1->next->prev = tmp1;
		*s = tmp2;
	}
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
