/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:57:50 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/30 18:06:29 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft.h"

# ifndef A
#  define A 1
# endif

# ifndef B
#  define B 2
# endif

typedef struct s_templist
{
	struct s_templist	*next;
	int					value;
	int					position;
}	t_templist;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_infos
{
	int	bef;
	int	aft;
	int	max;
	int	ord;
	int	where;
	int	size_a;
	int	size_b;
}	t_infos;

void		error_msg(char *str);

//read
void		check_args(int argc, char *argv[]);
void		check_overflow(char *nb, int size);
t_infos		*check_ordered(t_stack *stack, t_infos *inf);
t_templist	*get_values(int argc, char *argv[]);
void		check_list(int i, int value, t_templist **temp);
t_templist	*add_to_list(int i, int value);

//list utils
void		free_stack(t_stack *stack);
void		free_list(t_templist *temp);
t_stack		*get_last(t_stack *stack);
t_stack		*get_stack(t_templist *temp, t_infos **inf);
void		add_first(t_stack **stack, int value);
void		add_last(t_stack **stack, int value);
t_stack		*remove_element(t_stack *stack, t_stack *current, int is_first);

//sort
void		small_sort(t_stack **stack_a, t_stack **stack_b, t_infos *info);
void		sort_2(t_stack **stack_a, t_stack **stack_b, t_infos *info);
void		sort_3(t_stack **stack_a, t_stack **stack_b, t_infos *info);
void		first_iteration(t_stack **a, t_stack **b, t_infos *info);
void		protocol_a(t_stack **a, t_stack **b, t_infos **infos);
void		protocol_b1(t_stack **a, t_stack **b, t_infos **infos);
void		protocol_b2(t_stack **a, t_stack **b, t_infos **infos);
void		big_sort(t_stack **a, t_stack **b, t_infos **infos);
void		find_next(t_stack *a, t_stack *b, t_infos *infos);
t_infos		*check_distances(t_stack *stack, t_infos *inf);

//push_swap functions
void		push(t_stack **a, t_stack **b, char to, t_infos *info);
t_stack		*swap(t_stack *stack);
void		double_swap(t_stack **a, t_stack **b);
void		rotate(t_stack **stack);
void		reverse(t_stack **stack);
void		double_rotate(t_stack **a, t_stack **b);
void		double_reverse(t_stack **a, t_stack **b);
void		call_function(t_stack **a, t_stack **b, char *func, t_infos *info);

#endif