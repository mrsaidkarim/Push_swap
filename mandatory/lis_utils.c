/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:18:34 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:04:45 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_max(int i, int j)
{
	if (j > i)
		return (j);
	else
		return (i);
}

t_stack_node	*max_stack(t_stack_node *a)
{
	t_stack_node	*tmp;
	int				max;

	max = 1;
	tmp = a;
	while (a)
	{
		if (a->lis > max)
		{
			tmp = a;
			max = a->lis;
		}
		a = a->next;
	}
	return (tmp);
}

t_stack_node	*ft_last_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_flag(t_stack_node *a)
{
	t_stack_node	*tmp;
	int				max;

	tmp = max_stack(a);
	max = tmp->lis;
	while (max > 0)
	{
		if (tmp->lis == max)
		{
			tmp->f = 1;
			max--;
		}
		if (tmp->prev)
			tmp = tmp->prev;
		else
			tmp = ft_last_node(a);
	}
}

void	ft_lis(t_stack_node *a)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;
	int				i;

	i = ft_stack_len(a);
	tmp1 = smallest(a);
	while (i-- > 0)
	{
		tmp2 = smallest(a);
		while (tmp2 != tmp1)
		{
			if (tmp2->value < tmp1->value)
				tmp1->lis = ft_max(tmp1->lis, tmp2->lis + 1);
			if (tmp2->next)
				tmp2 = tmp2->next;
			else
				tmp2 = a;
		}
		if (tmp1->next)
			tmp1 = tmp1->next;
		else
			tmp1 = a;
	}
	ft_flag(a);
}
