/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:07:28 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:04:53 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	push(t_stack_node **s1, t_stack_node **s2)
{
	t_stack_node	*tmp;

	if (*s2)
	{
		tmp = *s2;
		*s2 = (*s2)->next;
		if (*s2)
			(*s2)->prev = NULL;
		if (*s1 == NULL)
		{
			*s1 = tmp;
			tmp->next = NULL;
		}
		else
		{
			(*s1)->prev = tmp;
			tmp->next = *s1;
			*s1 = tmp;
		}
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
