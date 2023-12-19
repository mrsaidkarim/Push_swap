/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:46:55 by skarim            #+#    #+#             */
/*   Updated: 2023/12/19 18:32:54 by skarim           ###   ########.fr       */
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
