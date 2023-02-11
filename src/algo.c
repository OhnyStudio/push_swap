/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/10 20:17:22 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo2(t_push **stack_a, t_push **stack_b)
{
	send_action("sa", stack_a, stack_b, 1);
}

void	algo3(t_push **stack_a, t_push **stack_b, int min, int max)
{
	t_push	*head;

	head = *stack_a;
	if (head->next->next->value == max)
		send_action("sa", stack_a, stack_b, 1);
	else if (head->value == max)
	{
		if (head->next->value != min)
		{
			send_action("ra", stack_a, stack_b, 1);
			send_action("sa", stack_a, stack_b, 1);
		}
		else
			send_action("ra", stack_a, stack_b, 1);
	}
	else
	{
		if (head->value == min)
		{
			send_action("rra", stack_a, stack_b, 1);
			send_action("sa", stack_a, stack_b, 1);
		}
		else
			send_action("rra", stack_a, stack_b, 1);
	}
}

void	algo4(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	second_min;

	min_to_top(stack_a, stack_b, min);
	send_action("pb", stack_a, stack_b, 1);
	second_min = find_min(stack_a);
	algo3(stack_a, stack_b, second_min, max);
	send_action("pa", stack_a, stack_b, 1);
}

void	algo_other(t_push **stack_a, t_push **stack_b, int min, int max)
{
	set_index(stack_a, min, 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
		new_algo(stack_a, stack_b, max);
}
