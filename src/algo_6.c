/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:34:06 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/10 14:35:25 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_stack_b(t_push **stack_a, t_push **stack_b)
{
	if (stack_size(*stack_b) > 1)
	{
		if ((*stack_b)->index > (*stack_b)->next->index)
			send_action("sb", stack_a, stack_b, 1);
	}
}

static void	split_stack(t_push **stack_a, t_push **stack_b, int nb_split, int i)
{
	long	split_origin;
	long	split_size;
	long	split_count;
	int		count;

	split_origin = stack_size(*stack_a) / nb_split;
	split_size = split_origin;
	split_count = 0;
	if (i == 1)
		count = split_origin;
	else
		count = 0;
	while (stack_size(*stack_a) > count)
	{
		if ((*stack_a)->index <= split_size)
		{
			split_count++;
			send_action("pb", stack_a, stack_b, 1);
			check_stack_b(stack_a, stack_b);
			if (split_count >= split_size)
				split_size += split_origin;
		}
		else
			send_action("ra", stack_a, stack_b, 1);
	}
}

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
		else
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

	split_stack(stack_a, stack_b, 2, 1);
	new_min = find_min(stack_a, 1);
	new_max = find_max(stack_b, 1);
	if (is_sorted(stack_a) == 0)
		algo3(stack_a, stack_b, new_min, max);
	if (is_reverse_sorted(stack_b) == 0)
		algo3_reverse(stack_a, stack_b, min, new_max);
	while (stack_size(*stack_b) > 0)
		send_action("pa", stack_a, stack_b, 1);
}
