/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:10:20 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:03:53 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_check_operation(t_stack_node **a, t_stack_node **b, char *opr)
{
	if (ft_strcmp(opr, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(opr, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(opr, "ss\n") == 0)
		swap_checker(a, b);
	else if (ft_strcmp(opr, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(opr, "pb\n") == 0)
		push(b, a);
	else if (ft_strcmp(opr, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(opr, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(opr, "rr\n") == 0)
		rotate_checker(a, b);
	else if (ft_strcmp(opr, "rra\n") == 0)
		rev_rotate(a);
	else if (ft_strcmp(opr, "rrb\n") == 0)
		rev_rotate(b);
	else if (ft_strcmp(opr, "rrr\n") == 0)
		rev_rotate_checker(a, b);
	else
		operation_error(a, b, opr);
}

void	ft_read_operations(t_stack_node **a, t_stack_node **b)
{
	char	*opr;

	opr = get_next_line(0);
	while (opr)
	{
		ft_check_operation(a, b, opr);
		free(opr);
		opr = get_next_line(0);
	}
}

void	valid_args(char **args)
{
	int	i;

	i = 0;
	if (!args[0])
	{
		ft_free(args);
		ft_putstr("Error\n");
		exit(-1);
	}
	while (args[i])
	{
		if (ft_arg_checker(args[i++]) == 0)
		{
			ft_putstr("Error\n");
			ft_free(args);
			exit(-1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*str;
	int				i;
	char			**tab;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	str = NULL;
	i = 1;
	while (i < argc)
		str = ft_join(str, argv[i++]);
	tab = ft_split(str, ' ');
	valid_args(tab);
	ft_init(&a, tab);
	ft_read_operations(&a, &b);
	if (ft_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&a), 0);
}
