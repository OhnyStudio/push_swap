/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/14 15:51:37 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	algo3(t_push **stack_a, t_push **stack_b, long min, long max)
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

static void	algo4(t_push **stack_a, t_push **stack_b, long min, long max)
{
	long	second_min;

	min_to_top_4(stack_a, stack_b, min);
	send_action("pb", stack_a, stack_b, 1);
	second_min = find_min(stack_a, 1);
	if (is_sorted(stack_a) == 0)
		algo3(stack_a, stack_b, second_min, max);
	send_action("pa", stack_a, stack_b, 1);
}

static void	algo5(t_push **stack_a, t_push **stack_b, long min, long max)
{
	long	second_min;

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

void	stack_to_top(t_push **stack_a, t_push **stack_b)
{
	t_push	*head_b;
	int		i;

	while (stack_size(*stack_b) > 0)
	{
		head_b = *stack_b;
		i = 0;
		while (head_b)
		{
			if (head_b->index == find_max(stack_b, 1))
				break ;
			head_b = head_b->next;
			i++;
		}
		if (i > 0)
		{
			if (i > stack_size(*stack_b) / 2)
				send_actions("rrb", stack_a, stack_b, stack_size(*stack_b) - i);
			else
				send_actions("rb", stack_a, stack_b, i);
		}
		send_action("pa", stack_a, stack_b, 1);
	}
}

static void	big_algo(t_push **stack_a, t_push **stack_b, long max)
{
	long	max_bit;
	long	bit;

	set_index(stack_a, find_min(stack_a, 0), 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else if (stack_size(*stack_a) > 100)
	{
		max_bit = find_max_bit(find_max(stack_a, 1));
		bit = 0;
		while (max_bit--)
		{
			if (is_sorted(stack_a) == 0)
				move_bit_a(stack_a, stack_b, bit++);
			if (is_reverse_sorted(stack_b) == 0)
				move_bit_b(stack_a, stack_b, bit);
		}
		while (stack_size(*stack_b) > 0)
			send_action("pa", stack_a, stack_b, 1);
	}
	else
	{
		split_stack(stack_a, stack_b, 6, 0);
		stack_to_top(stack_a, stack_b);
	}
}

void	sort_stack(t_push **stack_a, t_push **stack_b)
{
	long	size;
	long	min;
	long	max;

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
		big_algo(stack_a, stack_b, max);
}
