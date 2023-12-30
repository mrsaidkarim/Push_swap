/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:35:27 by skarim            #+#    #+#             */
/*   Updated: 2023/12/29 12:44:40 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// stack
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	int					f;
	int					lis;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

// functions
char			**ft_split(char *s, char c);
char			*ft_join(char *s1, char *s2);
void			ft_putstr(char *str);
int				ft_strlen(char *s);
long long		ft_atoi(char *s);
int				ft_arg_checker(char *s);
int				ft_dup(t_stack_node *a);
int				ft_sorted(t_stack_node *a);
void			ft_free(char **s);
void			push(t_stack_node **s1, t_stack_node **s2);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			swap(t_stack_node **s);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			rotate(t_stack_node **s);
void			rev_rotate(t_stack_node **s);
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
void			init_nodes(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_cheapest(t_stack_node *b);
void			move_to_a(t_stack_node **a, t_stack_node **b);
char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
void			ft_lis(t_stack_node *a);
void			operation_error(t_stack_node **a, t_stack_node **b, char *opr);
void			swap_checker(t_stack_node **a, t_stack_node **b);
void			rotate_checker(t_stack_node **a, t_stack_node **b);
void			rev_rotate_checker(t_stack_node **a, t_stack_node **b);
int				ft_max(int i, int j);

#endif