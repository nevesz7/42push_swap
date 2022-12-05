/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:32:40 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/05 13:17:30 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	protocol_a(t_stack **st_a, t_stack **st_b, t_infos **infos)
{
	t_stack	*a;
	t_infos	*info;

	info = *infos;
	a = *st_a;
	if (!(a->value == info->ord))
	{
		while (a->next->value != info->ord)
		{
			call_function(st_a, st_b, "pb", info);
			info->size_a--;
			info->size_b++;
			a = *st_a;
		}
		call_function(st_a, st_b, "sa", info);
	}
	call_function(st_a, st_b, "ra", info);
	info->size_a--;
	info->ord++;
}

void	protocol_b1(t_stack **st_a, t_stack **st_b, t_infos **infos)
{
	t_stack	*b;
	t_infos	*info;

	info = *infos;
	b = *st_b;
	if (!(b->value == info->ord))
	{
		while (b->next->value != info->ord)
		{
			if (info->size_b - 1 > info->size_a * 2)
			{
				call_function(st_a, st_b, "pa", info);
				info->size_a++;
				info->size_b--;
			}
			else
				call_function(st_a, st_b, "rb", info);
			b = *st_b;
		}
		if (b->next->value == info->ord)
			call_function(st_a, st_b, "sb", info);
	}
	call_function(st_a, st_b, "pa", info);
	call_function(st_a, st_b, "ra", info);
	info->size_b--;
	info->ord++;
}

void	protocol_b2(t_stack **st_a, t_stack **st_b, t_infos **infos)
{
	t_stack	*b;
	t_infos	*info;

	info = *infos;
	b = *st_b;
	while (b->value != info->ord)
	{
		call_function(st_a, st_b, "rrb", info);
		b = *st_b;
	}
	call_function(st_a, st_b, "pa", info);
	call_function(st_a, st_b, "ra", info);
	info->size_b--;
	info->ord++;
}

void	big_sort(t_stack **a, t_stack **b, t_infos **infos)
{
	t_infos	*info;

	info = *infos;
	info->size_a -= info->ord;
	while (info->ord <= info->max)
	{
		if (info->where == A)
			protocol_a(a, b, infos);
		if (info->where == B && info->bef <= info->aft)
			protocol_b1(a, b, infos);
		if (info->where == B && info->bef > info->aft)
			protocol_b2(a, b, infos);
		if (info->ord <= info->max)
		{
			find_next(*a, *b, info);
			if (info->where == A)
				check_distances(*a, info);
			else
				check_distances(*b, info);
		}
	}
}

void	find_next(t_stack *a, t_stack *b, t_infos *info)
{
	while (a)
	{
		if (a->value == info->ord)
			info->where = A;
		a = a->next;
	}
	while (b)
	{
		if (b->value == info->ord)
			info->where = B;
		b = b->next;
	}
}
