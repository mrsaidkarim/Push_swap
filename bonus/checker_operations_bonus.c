/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:10:10 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:03:58 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	operation_error(t_stack_node **a, t_stack_node **b, char *opr)
{
	free_stack(a);
	free_stack(b);
	free(opr);
	ft_putstr("Error\n");
	exit(1);
}

void	swap_checker(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}

void	rotate_checker(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}

void	rev_rotate_checker(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
