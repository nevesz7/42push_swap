/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:15:11 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/11 20:57:06 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	check_args(int argc, char *argv[])
{
	if (argc == 1)
		exit(0);
	while (argc-- > 1)
	{
		if (!(ft_strisdigit(argv[argc])))
			error_msg("Error");
		check_overflow(argv[argc], (int)ft_strlen(argv[argc]));
	}
}

void	check_list(int i, int value, t_templist **temp, t_infos **infos)
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
		{
			free(*infos);
			free_list(*temp);
			error_msg("Error");
		}
		if (value > aux->value)
			i++;
		else
			aux->position++;
		if (!aux->next)
			break ;
		aux = aux->next;
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
		error_msg("Error");
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}
