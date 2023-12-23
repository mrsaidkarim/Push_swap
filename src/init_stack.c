/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:36:35 by skarim            #+#    #+#             */
/*   Updated: 2023/12/23 10:49:19 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add(t_stack_node **stk, int n)
{
	t_stack_node	*node;
	t_stack_node	*tmp;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	node->value = n;
	node->next = NULL;
	if (*stk == NULL)
	{
		*stk = node;
		node->prev = NULL;
	}
	else
	{
		tmp = *stk;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
}

void	ft_free_stack(t_stack_node **a, char **args)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	*a = NULL;
	ft_free(args);
	exit(1);
}

void	ft_init(t_stack_node **a, char **args)
{
	int				i;

	i = 0;
	while (args[i])
		ft_add(a, atoi(args[i++]));
	if (ft_dup(*a))
	{
		ft_putstr("Error\n");
		ft_free_stack(a, args);
	}
	else
		ft_free(args);
}

void	free_stack(t_stack_node **s)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	tmp1 = *s;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	*s = NULL;
}
