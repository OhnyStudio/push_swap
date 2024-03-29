/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:45:03 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/15 14:52:12 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_bit(int index, int bit)
{
	if (index & (1 << bit))
		return (1);
	return (0);
}

int	find_max_bit(long max)
{
	long	bit;
	int		i;

	i = 1;
	bit = 2;
	while (max > bit)
	{
		bit *= 2;
		i++;
	}
	return (i);
}

void	move_bit_b(t_push **stack_a, t_push **stack_b, int bit)
{
	long	size;

	size = stack_size(*stack_b);
	while (size--)
	{
		if (check_bit((*stack_b)->index, bit) == 1)
			send_action("pa", stack_a, stack_b, 1);
		else
			send_action("rb", stack_a, stack_b, 1);
	}
}

void	move_bit_a(t_push **stack_a, t_push **stack_b, int bit)
{
	int	size;

	size = stack_size(*stack_a);
	while (size--)
	{
		if (check_bit((*stack_a)->index, bit) == 0)
			send_action("pb", stack_a, stack_b, 1);
		else
			send_action("ra", stack_a, stack_b, 1);
	}
}

void	big_algo(t_push **stack_a, t_push **stack_b, long max)
{
	long	max_bit;
	long	bit;

	if (find_if_backward(stack_a) != 0)
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
