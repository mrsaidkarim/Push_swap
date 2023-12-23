/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:46:55 by skarim            #+#    #+#             */
/*   Updated: 2023/12/20 19:15:04 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_checker(char *s)
{
	int	i;
	int	checked;

	i = 0;
	checked = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		else
			checked = 1;
		i++;
	}
	if (checked == 0 || ft_atoi(s) > INT_MAX || ft_atoi(s) < INT_MIN)
		return (0);
	return (1);
}

int	ft_dup(t_stack_node *a)
{
	t_stack_node	*tmp;

	if (a)
	{
		while (a)
		{
			tmp = a->next;
			while (tmp)
			{
				if (tmp->value == a->value)
					return (1);
				tmp = tmp->next;
			}
			a = a->next;
		}
	}
	return (0);
}

int	ft_sorted(t_stack_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
