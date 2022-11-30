/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:45 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/25 02:01:00 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	add_last(stack, aux->value);
	*stack = remove_element(aux, aux, 1);
}

void	reverse(t_stack **stack)
{
	t_stack	*aux;

	aux = get_last(*stack);
	add_first(stack, aux->value);
	*stack = remove_element(*stack, aux, 0);
}

void	double_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	double_reverse(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}
