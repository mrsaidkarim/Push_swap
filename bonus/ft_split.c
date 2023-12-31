/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:23:00 by skarim            #+#    #+#             */
/*   Updated: 2023/12/30 16:04:32 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

static int	ft_count(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_word(char *str, char c)
{
	int		end;
	int		i;
	char	*s;

	end = 0;
	while (str[end] && str[end] != c)
		end++;
	s = (char *)malloc(sizeof(char) * (end + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < end)
	{
		s[i] = str[i];
		i++;
	}
	s[end] = '\0';
	return (s);
}

static char	**ft_free_split(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		i;
	int		count;
	char	*tmp;

	tmp = s;
	count = ft_count(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	i = 0;
	res[count] = NULL;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		res[i] = ft_word(s, c);
		if (res[i] == NULL)
			return (ft_free_split(res, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	free(tmp);
	return (res);
}
