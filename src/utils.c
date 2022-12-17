/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:01:18 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/11 20:50:26 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	free_list(t_templist *temp)
{
	t_templist	*aux;

	while (temp->next)
	{
		aux = temp;
		temp = temp->next;
		free (aux);
	}
	free (temp);
}

void	free_stack(t_stack *stack)
{
	t_stack	*aux;

	while (stack->next)
	{
		aux = stack;
		stack = stack->next;
		free (aux);
	}
	free (stack);
}

void	free_(t_stack **a, t_stack **b, t_templist **temp, t_infos **infos)
{
	free_stack(*a);
	free_stack(*b);
	free_list(*temp);
	free(*infos);
	exit(0);
}

void	error_msg(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}
