/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:32:40 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/11 23:32:25 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	big_sort(t_stack **s_a, t_stack **s_b, t_infos *inf)
{
	while (inf->div / 2 <= inf->max)
	{
		do_a(s_a, s_b, inf->div);
		do_b(s_a, s_b);
		inf->div *= 2;
	}
}

void	do_a(t_stack **s_a, t_stack **s_b, int div)
{
	t_stack	*a;
	t_stack	*b;

	a = *s_a;
	b = *s_b;
	while (a->value != -1)
	{
		if (a->value % div < div / 2)
			call_function(&a, &b, "pb");
		else
			call_function(&a, &b, "ra");
	}
	rotate(&a);
	*s_a = a;
	*s_b = b;
}

void	do_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *s_a;
	b = *s_b;
	while (b->value != -1)
		call_function(&a, &b, "pa");
	*s_a = a;
	*s_b = b;
}
