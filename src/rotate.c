/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:31:39 by skarim            #+#    #+#             */
/*   Updated: 2023/12/22 16:37:09 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **s)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (*s)
	{
		tmp = *s;
		last = *s;
		if ((*s)->next == NULL)
			return ;
		while (last->next)
			last = last->next;
		*s = (*s)->next;
		(*s)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = last;
		last->next = tmp;
	}
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
