/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:11:23 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/13 04:52:07 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	small_sort(t_stack **a, t_stack **b, int max)
{
	t_stack	*st;

	st = *a;
	if (max == 1)
		sort_2(a, b, *a);
	if (max == 2)
		sort_3(a, b, *a);
	if (max == 3)
		sort_4(a, b, *a, st->value);
	if (max == 4)
		sort_5(a, b, *a);
}

void	sort_2(t_stack **a, t_stack **b, t_stack *st)
{
	if (st->value > st->next->value)
		call_function(a, b, "sa");
}

void	sort_3(t_stack **a, t_stack **b, t_stack *st)
{
	if (stack_is_sorted(st))
		return ;
	if (st->value > st->next->value && st->value < st->next->next->value)
	{
		call_function(a, b, "sa");
		return ;
	}
	if (st->value < st->next->value && st->value > st->next->next->value)
	{
		call_function(a, b, "rra");
		return ;
	}
	if (st->value < st->next->value && st->value < st->next->next->value)
	{
		call_function(a, b, "rra");
		sort_3(a, b, *a);
		return ;
	}
	if (st->value > st->next->value && st->next->value > st->next->next->value)
	{
		call_function(a, b, "sa");
		sort_3(a, b, *a);
	}
	else if (st->value > st->next->value && st->value > st->next->next->value)
		call_function(a, b, "ra");
}

void	sort_4(t_stack **a, t_stack **b, t_stack *st, int value)
{
	if (stack_is_sorted(st))
		return ;
	if (value == 0 || value == 3)
	{
		call_function(a, b, "pb");
		sort_3(a, b, *a);
		call_function(a, b, "pa");
		if (value == 3)
			call_function(a, b, "ra");
	}
	else if (value == 1)
	{
		call_function(a, b, "pb");
		sort_3(a, b, *a);
		call_function(a, b, "pa");
		call_function(a, b, "sa");
	}
	else if (value == 2)
	{
		call_function(a, b, "sa");
		st = *a;
		sort_4(a, b, *a, st->value);
	}
}

void	sort_5(t_stack **a, t_stack **b, t_stack *st)
{
	if (stack_is_sorted(st))
		return ;
	if (st->next->next->next->value == 4)
		call_function(a, b, "rra");
	st = *a;
	if (st->next->next->next->next->value == 4)
		call_function(a, b, "rra");
	st = *a;
	if (st->next->next->value == 4)
		call_function(a, b, "ra");
	st = *a;
	if (st->next->value == 4)
		call_function(a, b, "ra");
	st = *a;
	if (st->value == 4)
	{
		call_function(a, b, "pb");
		st = *a;
		sort_4(a, b, st, st->value);
		call_function(a, b, "pa");
		call_function(a, b, "ra");
	}
}
