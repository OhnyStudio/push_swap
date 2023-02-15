/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:27 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/15 16:54:12 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_min_max(t_push **stack_a, t_push **stack_b, int min, int max)
{
	char	*action;

	if ((*stack_a)->value == min)
	{
		if (ra_or_rra(stack_b, find_max(stack_b)) == 0)
			action = "rb";
		else
			action = "rrb";
		while ((*stack_b)->value != find_min(stack_b))
			send_action(action, stack_a, stack_b, 1);
		return (1);
	}
	else if ((*stack_a)->value == max)
	{
		if (ra_or_rra(stack_b, find_max(stack_b)) == 0)
			action = "rrb";
		else
			action = "rb";
		while ((*stack_b)->value != find_max(stack_b))
			send_action(action, stack_a, stack_b, 1);
		return (1);
	}
	return (0);
}

static void	insert_to_b(t_push **stack_a, t_push **stack_b, int min, int max)
{
	t_push	*head_a;
	t_push	*head_b;
	int		previous;

	head_a = *stack_a;
	previous = (*stack_b)->value;
	send_action("rb", stack_a, stack_b, 1);
	head_b = *stack_b;
	while (head_a)
	{
		if (is_min_max(stack_a, stack_b, min, max) == 0)
		{
			while (head_a->value > previous || head_a->value < head_b->value)
			{
				previous = head_b->value;
				send_action("rb", stack_a, stack_b, 1);
				head_b = *stack_b;
			}
		}
		send_action("pb", stack_a, stack_b, 1);
		head_a = *stack_a;
		head_b = *stack_b;
	}
}

static void	send_double_action(t_push **stack_a, t_push **stack_b)
{
	send_action("pb", stack_a, stack_b, 1);
	send_action("rb", stack_a, stack_b, 1);
}

static void	swap_to_b(t_push **stack_a, t_push **stack_b, int size)
{
	t_push	*head;
	t_push	*tmp;
	int		min_max[2];

	min_max[0] = (*stack_a)->value;
	min_max[1] = (*stack_a)->value;
	send_action("pb", stack_a, stack_b, 1);
	head = *stack_a;
	while (--size > 1)
	{
		tmp = head->next;
		if (head->value > min_max[1])
		{
			min_max[1] = head->value;
			send_action("pb", stack_a, stack_b, 1);
		}
		else if (head->value < min_max[0])
		{
			min_max[0] = head->value;
			send_double_action(stack_a, stack_b);
		}
		else
			send_action("ra", stack_a, stack_b, 1);
		head = tmp;
	}
}

void	new_algo(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int		size;

	size = stack_size(*stack_a);
	swap_to_b(stack_a, stack_b, size);
	insert_to_b(stack_a, stack_b, min, max);
	while (stack_size(*stack_b) > 0)
		send_action("pa", stack_a, stack_b, 1);
	make_rotation(stack_a, stack_b, max);
}
