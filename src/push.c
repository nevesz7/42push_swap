/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:56:29 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/30 17:02:17 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_templist	*temp;
	t_infos		*inf;

	inf = (t_infos *)malloc(sizeof(t_infos));
	check_args(argc, argv);
	temp = get_values(argc, argv);
	stack_a = get_stack(get_values(argc, argv), &inf);
	stack_b = NULL;
	add_last(&stack_b, -1);
	inf = check_ordered(stack_a, inf);
	inf->size_b = 0;
	if (inf->aft > 0)
		first_iteration(&stack_a, &stack_b, inf);
	big_sort(&stack_a, &stack_b, &inf);
	if (inf->max == 1)
		sort_2(&stack_a, &stack_b, inf);
	if (inf->max == 2)
		sort_3(&stack_a, &stack_b, inf);
	free_stack(stack_a);
	free_stack(stack_b);
	free_list(temp);
	free(inf);
	return (0);
}

void	first_iteration(t_stack **a, t_stack **b, t_infos *info)
{
	int		i;

	i = -1;
	if (info->bef + info->ord + 1 <= info->aft)
	{
		while (++i < info->bef)
		{
			call_function(a, b, "pb", info);
			info->size_a--;
			info->size_b++;
		}
		while (++i <= info->bef + info->ord + 1)
			call_function(a, b, "ra", info);
	}
	else
	{
		while (++i < info->aft)
			call_function(a, b, "rra", info);
	}
	info->ord++;
	find_next(*a, *b, info);
	if (info->where == A)
		check_distances(*a, info);
	else
		check_distances(*b, info);
}
