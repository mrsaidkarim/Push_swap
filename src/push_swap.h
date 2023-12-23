/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:35:27 by skarim            #+#    #+#             */
/*   Updated: 2023/12/23 13:11:57 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
// stack
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

// functions
char			**ft_split(char *s, char c);
char			*ft_join(char *s1, char *s2);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
long long		ft_atoi(char *s);
int				ft_arg_checker(char *s);
int				ft_dup(t_stack_node *a);
int				ft_sorted(t_stack_node *a);
void			ft_free(char **s);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ft_init(t_stack_node **a, char **args);
void			ft_sort(t_stack_node **a, t_stack_node **b);
int				ft_sorted(t_stack_node *a);
void			free_stack(t_stack_node **s);
int				ft_stack_len(t_stack_node *s);
void			ft_set_index(t_stack_node *s);
t_stack_node	*smallest(t_stack_node *a);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			init_nodes(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_cheapest(t_stack_node *b);
void			move_to_a(t_stack_node **a, t_stack_node **b);

#endif