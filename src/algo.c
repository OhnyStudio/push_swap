/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/07 19:39:41 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	algo3(t_push **stack_a, t_push **stack_b, int min, int max)
{
	if ((*stack_a)->index == min)
	{
		send_action("rra", stack_a, stack_b, 1);
		send_action("sa", stack_a, stack_b, 1);
	}
	else if ((*stack_a)->index == max)
	{
		send_action("ra", stack_a, stack_b, 1);
		if ((*stack_a)->index != min)
			send_action("sa", stack_a, stack_b, 1);
	}
	else
	{
		if ((*stack_a)->next->index == min)
			send_action("sa", stack_a, stack_b, 1);
		else
			send_action("rra", stack_a, stack_b, 1);
	}
}

static void	algo4(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	second_min;

	min_to_top_4(stack_a, stack_b, min);
	send_action("pb", stack_a, stack_b, 1);
	second_min = find_min(stack_a, 1);
	if (is_sorted(stack_a) == 0)
		algo3(stack_a, stack_b, second_min, max);
	send_action("pa", stack_a, stack_b, 1);
}

static void	algo5(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	second_min;

	min_to_top_5(stack_a, stack_b, min);
	if (is_sorted(stack_a) == 0)
	{
		send_action("pb", stack_a, stack_b, 1);
		second_min = find_min(stack_a, 1);
		if (is_sorted(stack_a) == 0)
		{
			min_to_top_4(stack_a, stack_b, second_min);
			if (is_sorted(stack_a) == 0)
			{
				send_action("pb", stack_a, stack_b, 1);
				second_min = find_min(stack_a, 1);
				if (is_sorted(stack_a) == 0)
					algo3(stack_a, stack_b, second_min, max);
				send_action("pa", stack_a, stack_b, 1);
			}
		}
		send_action("pa", stack_a, stack_b, 1);
	}
}

void	sort_stack(t_push **stack_a, t_push **stack_b)
{
	int	size;
	int	min;
	int	max;

	min = find_min(stack_a, 0);
	set_index(stack_a, min, 2);
	min = find_min(stack_a, 1);
	max = find_max(stack_a, 1);
	size = stack_size(*stack_a);
	if (size == 2)
		send_action("sa", stack_a, stack_b, 1);
	else if (size == 3)
		algo3(stack_a, stack_b, min, max);
	else if (size == 4)
		algo4(stack_a, stack_b, min, max);
	else if (size == 5)
		algo5(stack_a, stack_b, min, max);
	else if (size == 6)
		algo6(stack_a, stack_b, min, max);
	else if (size > 6)
		big_algo(stack_a, stack_b, min, max);
	(void)stack_b;
}
