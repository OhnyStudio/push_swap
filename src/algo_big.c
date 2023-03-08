/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:45:03 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/08 11:21:03 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	max_to_top(t_push **stack_a, t_push **stack_b)
{
	t_push	*head_b;
	int		max;

	max = find_max(stack_b, 1);
	head_b = *stack_b;
	while (head_b->index != max)
	{
		send_action("rb", stack_a, stack_b, 1);
		head_b = *stack_b;
	}
}

void	big_algo(t_push **stack_a, t_push **stack_b, int min, int max)
{
	(void)min;
	set_index(stack_a, find_min(stack_a, 0), 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
	{
		if (stack_size(*stack_a) >= 500)
			split_sort(stack_a, stack_b, 11);
		else
			split_sort(stack_a, stack_b, 5);
		max_to_top(stack_a, stack_b);
		while (stack_size(*stack_b) > 0)
			send_action("pa", stack_a, stack_b, 1);
	}
}
