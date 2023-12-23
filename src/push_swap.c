/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:40:37 by skarim            #+#    #+#             */
/*   Updated: 2023/12/23 15:54:16 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*str;
	int				i;
	char			**args;

	a = NULL;
	b = NULL;
	str = NULL;
	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
		str = ft_join(str, argv[i++]);
	if (str == NULL)
		return (1);
	args = ft_split(str, ' ');
	i = 0;
	while (args[i])
		if (ft_arg_checker(args[i++]) == 0)
			return (ft_putstr("Error\n"), ft_free(args), 0);
	ft_init(&a, args);
	if (!ft_sorted(a))
		ft_sort(&a, &b);
	return (free_stack(&a), 0);
}
