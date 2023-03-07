/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:34:06 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/07 13:12:42 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	algo3(t_push **stack_a, t_push **stack_b, int min, int max)
{
	if ((*stack_a)->index == min)
	{
		send_action("rra", stack_a, stack_b, 1);
		if ((*stack_b)->index == find_max(stack_a, 1) == 1)
		{
			send_action("ss", stack_a, stack_b, 1);
			send_action("rb", stack_a, stack_b, 1);
		}
		else
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

static void	algo3_reverse(t_push **stack_a, t_push **stack_b, int min, int max)
{
	if ((*stack_b)->index == max)
	{
		send_action("sb", stack_a, stack_b, 1);
		send_action("rb", stack_a, stack_b, 1);
	}
	else if ((*stack_b)->index == min)
	{
		if ((*stack_b)->next->index != max)
		{
			send_action("sb", stack_a, stack_b, 1);
			send_action("rrb", stack_a, stack_b, 1);
		}
		send_action("rb", stack_a, stack_b, 1);
	}
	else
	{
		if ((*stack_b)->next->index != max)
			send_action("rrb", stack_a, stack_b, 1);
		else
			send_action("sb", stack_a, stack_b, 1);
	}
}

void	algo6(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	new_min;
	int	new_max;

	set_index(stack_a, min, 2);
	split_stack_nb(stack_a, stack_b, 2, 1);
	new_min = find_min(stack_a, 1);
	new_max = find_max(stack_b, 1);
	if (is_sorted(stack_a) == 0)
		algo3(stack_a, stack_b, new_min, max);
	if (is_reverse_sorted(stack_b) == 0)
		algo3_reverse(stack_a, stack_b, min, new_max);
	while (stack_size(*stack_b) > 0)
		send_action("pa", stack_a, stack_b, 1);
}
