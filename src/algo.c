/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/22 16:00:02 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	complexe_algo(t_push **a, t_push **b, int min, int max)
{
	int	size;
	int	median;	

	size = stack_size(*a);
	median = find_median(a);
	if (size > 20)
	{
		split_median(a, b);
		while (stack_size(*b) > 0)
			send_action("pa", a, b, 1);
	}
	swap_to_b(a, b, size);
	insert_to_b(a, b, min, max);
	while (stack_size(*b) > 0)
		send_action("pa", a, b, 1);
	make_rotation(a, b, max);
}

static void	algo3(t_push **stack_a, t_push **stack_b, int min, int max)
{
	if ((*stack_a)->value == min)
	{
		send_action("rra", stack_a, stack_b, 1);
		send_action("sa", stack_a, stack_b, 1);
	}
	else if ((*stack_a)->value == max)
	{
		send_action("ra", stack_a, stack_b, 1);
		if ((*stack_a)->value != min)
			send_action("sa", stack_a, stack_b, 1);
	}
	else
	{
		if ((*stack_a)->next->value == min)
			send_action("sa", stack_a, stack_b, 1);
		else
			send_action("rra", stack_a, stack_b, 1);
	}
}

static void	algo4(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	second_min;

	min_to_top(stack_a, stack_b, min);
	send_action("pb", stack_a, stack_b, 1);
	second_min = find_min(stack_a);
	if (is_sorted(stack_a) == 0)
		algo3(stack_a, stack_b, second_min, max);
	send_action("pa", stack_a, stack_b, 1);
}

static void	big_algo(t_push **stack_a, t_push **stack_b, int min, int max)
{
	set_index(stack_a, min, 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
		complexe_algo(stack_a, stack_b, min, max);
}

void	sort_stack(t_push **stack_a, t_push **stack_b)
{
	int	size;
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	size = stack_size(*stack_a);
	if (size == 2)
		send_action("sa", stack_a, stack_b, 1);
	else if (size == 3)
		algo3(stack_a, stack_b, min, max);
	else if (size == 4)
		algo4(stack_a, stack_b, min, max);
	else if (size > 4)
		big_algo(stack_a, stack_b, min, max);
	(void)stack_b;
}