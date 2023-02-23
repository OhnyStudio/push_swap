/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/23 16:06:46 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	complexe_algo(t_push **a, t_push **b, int min, int max)
// {
// 	int	size;

// 	size = stack_size(*a);
// 	split_median(a, b);
// 	while (stack_size(*b) > 0)
// 		send_action("pa", a, b, 1);
// 	swap_to_b(a, b, size);
// 	insert_to_b(a, b, min, max);
// 	while (stack_size(*b) > 0)
// 		send_action("pa", a, b, 1);
// 	make_rotation(a, b, max);
// }

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
	int	temp;
	int	max_bit;

	temp = 3;
	max_bit = 0;
	set_index(stack_a, min, 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
	{
		max_bit = find_max_bit(find_max(stack_a, 1));
		check_bit(stack_a, stack_b, 0, max_bit);
		set_backward(stack_a, stack_b, max);
	}
}

void	sort_stack(t_push **stack_a, t_push **stack_b)
{
	int	size;
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a, 0);
	size = stack_size(*stack_a);
	if (size == 2)
		send_action("sa", stack_a, stack_b, 1);
	else if (size == 3)
		algo3(stack_a, stack_b, min, max);
	else if (size == 4)
		algo4(stack_a, stack_b, min, max);
	else if (size == 5)
		ft_putstr_fd("5\n", 1);
	else if (size == 6)
		ft_putstr_fd("6\n", 1);
	else if (size > 6)
		big_algo(stack_a, stack_b, min, max);
	(void)stack_b;
}
