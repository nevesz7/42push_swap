/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:15:11 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/30 16:42:52 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	check_args(int argc, char *argv[])
{
	while (argc-- > 1)
	{
		if (!(ft_strisdigit(argv[argc])))
			error_msg("Please insert only valid numbers.");
		check_overflow(argv[argc], (int)ft_strlen(argv[argc]));
	}
}

void	check_list(int i, int value, t_templist **temp)
{
	t_templist	*aux;

	if (!*temp)
	{
		*temp = add_to_list(i, value);
		return ;
	}
	aux = *temp;
	while (aux)
	{
		if (value == aux->value)
			error_msg("Please dont insert repeated numbers.");
		if (value > aux->value)
			i++;
		else
			aux->position++;
		if (aux->next)
			aux = aux->next;
		else
			break ;
	}
	aux->next = add_to_list(i, value);
}

void	check_overflow(char *nb, int size)
{
	int	aux;
	int	no;

	no = 0;
	aux = 10;
	if (*nb == '-')
		aux++;
	while (*nb == '+' || *nb == '0')
	{
		nb++;
		size--;
	}
	if (size < aux)
		no++;
	if (size == aux)
	{
		if (*nb == '-')
			aux = ft_strncmp(nb, "-2147483648", 11);
		else
			aux = ft_strncmp(nb, "2147483647", 10);
	}
	if (aux <= 0)
		no++;
	if (no == 0)
		error_msg("Please insert only numbers that fit into an int.");
}

t_infos	*check_distances(t_stack *stack, t_infos *inf)
{
	inf->bef = 0;
	inf->aft = 0;
	while (stack->value != inf->ord)
	{
		stack = stack->next;
		inf->bef++;
	}
	while (stack->next && stack->next->value != 0)
	{
		stack = stack->next;
		inf->aft++;
	}
	return (inf);
}

t_infos	*check_ordered(t_stack *stack, t_infos *inf)
{
	inf->bef = 0;
	inf->aft = 0;
	inf->ord = 0;
	while (stack->value != inf->ord)
	{
		stack = stack->next;
		inf->bef++;
	}
	while (stack->next)
	{
		if (stack->next->value == (stack->value + 1))
			inf->ord++;
		else
			break ;
		stack = stack->next;
	}
	while (stack->next)
	{
		stack = stack->next;
		inf->aft++;
	}
	return (inf);
}
