/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:44 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/30 16:42:12 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack	*swap(t_stack *stack)
{
	int	value;

	value = stack->next->value;
	remove_element(stack, stack->next, 0);
	add_first(&stack, value);
	return (stack);
}

void	double_swap(t_stack **a, t_stack **b)
{
	*a = swap(*a);
	*b = swap(*b);
}

//from to
void	push(t_stack **a, t_stack **b, char aux, t_infos *info)
{
	t_stack	*to;
	t_stack	*from;

	if (aux == 'a')
	{
		from = *b;
		if (info->size_b == 1)
			add_last(&from, -1);
		add_first(a, from->value);
		*b = remove_element(from, from, 1);
	}
	else
	{
		from = *a;
		add_first(b, from->value);
		*a = remove_element(from, from, 1);
		to = *b;
		if (info->size_b == 0)
			remove_element(to, to->next, 0);
	}
}

void	call_function(t_stack **a, t_stack **b, char *func, t_infos *info)
{
	ft_printf("%s\n", func);
	if (!(ft_strncmp(func, "sa", 3)))
		*a = swap(*a);
	if (!(ft_strncmp(func, "sb", 3)))
		*b = swap(*b);
	if (!(ft_strncmp(func, "ss", 3)))
		double_swap(a, b);
	if ((!(ft_strncmp(func, "pa", 3))) || (!(ft_strncmp(func, "pb", 3))))
		push(a, b, func[1], info);
	if (!(ft_strncmp(func, "ra", 3)))
		rotate(a);
	if (!(ft_strncmp(func, "rb", 3)))
		rotate(b);
	if (!(ft_strncmp(func, "rr", 3)))
		double_rotate(a, b);
	if (!(ft_strncmp(func, "rra", 3)))
		reverse(a);
	if (!(ft_strncmp(func, "rrb", 3)))
		reverse(b);
	if (!(ft_strncmp(func, "rrr", 3)))
		double_reverse(a, b);
}
