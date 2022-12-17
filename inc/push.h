/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:57:50 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/13 04:43:58 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft.h"

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
	int	max;
	int	div;
}	t_infos;

void		error_msg(char *str);
void		free_(t_stack **a, t_stack **b, t_templist **temp, t_infos **infos);

//read
void		check_args(int argc, char *argv[]);
void		check_overflow(char *nb, int size);
int			stack_is_sorted(t_stack *stack);
t_templist	*get_values(int argc, char *argv[], t_infos **infos);
void		check_list(int i, int value, t_templist **temp, t_infos **infos);
t_templist	*add_to_list(int i, int value);

//list/stack utils
void		free_stack(t_stack *stack);
void		free_list(t_templist *temp);
t_stack		*get_last(t_stack *stack);
t_stack		*get_stack(t_templist *temp, t_infos **infos);
void		add_first(t_stack **stack, int value);
void		add_last(t_stack **stack, int value);
t_stack		*remove_element(t_stack *stack, t_stack *current, int is_first);

//sort
void		small_sort(t_stack **a, t_stack **b, int max);
void		sort_2(t_stack **a, t_stack **b, t_stack *st);
void		sort_3(t_stack **a, t_stack **b, t_stack *st);
void		sort_4(t_stack **a, t_stack **b, t_stack *st, int value);
void		sort_5(t_stack **a, t_stack **b, t_stack *st);
void		big_sort(t_stack **s_a, t_stack **s_b, t_infos *inf);
void		do_a(t_stack **s_a, t_stack **s_b, int div);
void		do_b(t_stack **s_a, t_stack **s_b);

//push_swap functions
void		push(t_stack **a, t_stack **b, char aux);
t_stack		*swap(t_stack *stack);
void		double_swap(t_stack **a, t_stack **b);
void		rotate(t_stack **stack);
void		reverse(t_stack **stack);
void		double_rotate(t_stack **a, t_stack **b);
void		double_reverse(t_stack **a, t_stack **b);
void		call_function(t_stack **a, t_stack **b, char *func);

#endif