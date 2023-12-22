/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:46:05 by skarim            #+#    #+#             */
/*   Updated: 2023/12/22 16:37:32 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **s)
{
	t_stack_node	*last;

	if (*s)
	{
		last = *s;
		if ((*s)->next == NULL)
			return ;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->next = (*s);
		last->prev = NULL;
		(*s)->prev = last;
		*s = last;
	}
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
