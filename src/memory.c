/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:19:06 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/30 16:55:34 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_templist	*get_values(int argc, char *argv[])
{
	t_templist	*temp;
	int			i;

	temp = NULL;
	i = 0;
	while (++i < argc)
		check_list(0, ft_atoi(argv[i]), &temp);
	return (temp);
}

t_templist	*add_to_list(int i, int value)
{
	t_templist	*new;

	new = (t_templist *)malloc(sizeof(t_templist));
	new->value = value;
	new->position = i;
	new->next = NULL;
	return (new);
}

t_stack	*get_stack(t_templist *temp, t_infos **infos)
{
	t_stack	*stack;
	t_infos	*inf;

	inf = *infos;
	inf->max = -1;
	stack = NULL;
	while (temp)
	{
		add_last(&stack, temp->position);
		inf->max++;
		temp = temp->next;
	}
	inf->size_a = inf->max;
	inf->size_b = 0;
	inf->where = A;
	return (stack);
}

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
