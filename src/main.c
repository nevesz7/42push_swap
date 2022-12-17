/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:56:29 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/11 23:33:00 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_templist	*temp;
	t_infos		*inf;

	check_args(argc, argv);
	inf = (t_infos *)malloc(sizeof(t_infos));
	temp = get_values(argc, argv, &inf);
	a = get_stack(temp, &inf);
	b = NULL;
	add_last(&b, -1);
	if (stack_is_sorted(a))
		free_(&a, &b, &temp, &inf);
	inf->div = 2;
	if (inf->max <= 4)
		small_sort(&a, &b, inf->max);
	add_last(&a, -1);
	if (inf->max > 4)
		big_sort(&a, &b, inf);
	free_(&a, &b, &temp, &inf);
}
