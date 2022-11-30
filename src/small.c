/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:11:23 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/29 21:01:22 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_2(t_stack **stack_a, t_stack **stack_b, t_infos *info)
{
	t_stack	*stack;

	stack = *stack_a;
	if (stack->value)
		call_function(stack_a, stack_b, "sa", info);
}

void	sort_3(t_stack **stack_a, t_stack **stack_b, t_infos *info)
{
	t_stack	*stack;

	stack = *stack_a;
	if (stack->value == 0 && stack->next->value == 2)
	{
		call_function(stack_a, stack_b, "sa", info);
		sort_3(stack_a, stack_b, info);
	}
	if (stack->value == 2 && stack->next->value == 1)
	{
		call_function(stack_a, stack_b, "ra", info);
		sort_3(stack_a, stack_b, info);
	}
	if (stack->value == 1 && stack->next->value == 2)
		call_function(stack_a, stack_b, "rra", info);
	if (stack->value == 2 && stack->next->value == 0)
		call_function(stack_a, stack_b, "ra", info);
	if (stack->value == 1 && stack->next->value == 0)
		call_function(stack_a, stack_b, "sa", info);
}
