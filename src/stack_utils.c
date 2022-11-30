/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:48 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/29 21:27:52 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	add_first(t_stack **stack, int value)
{
	t_stack	*new;

	if (!stack)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = value;
	if (*stack)
		new->next = *stack;
	else
		new->next = NULL;
	*stack = new;
}

void	add_last(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return ;
	if (!*stack)
	{
		add_first(stack, value);
		return ;
	}
	last = get_last(*stack);
	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	last->next = new;
}

t_stack	*remove_element(t_stack *stack, t_stack *current, int is_first)
{
	t_stack	*aux;

	aux = stack;
	if (is_first)
	{
		stack = current->next;
		free(current);
		return (stack);
	}
	while (aux->next != current)
		aux = aux->next;
	aux->next = current->next;
	free(current);
	return (stack);
}

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
