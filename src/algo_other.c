/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:27 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/11 11:28:33 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_to_b(t_push **stack_a, t_push **stack_b)
{
	t_push	*head_a;
	t_push	*head_b;
	t_push	*previous;

	head_a = *stack_a;
	previous = *stack_b;
	send_action("rb", stack_a, stack_b, 1);
	head_b = *stack_b;
	while (stack_size(*stack_a) != 0)
	{
		while (head_a->value > previous->value
			|| head_a->value < head_b->value)
		{
			previous = head_b;
			send_action("rb", stack_a, stack_b, 1);
			head_b = *stack_b;
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
	while (size--)
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

void	new_algo(t_push **stack_a, t_push **stack_b, int max)
{
	int		size;

	size = stack_size(*stack_a);
	swap_to_b(stack_a, stack_b, size);
	insert_to_b(stack_a, stack_b);
	while (stack_size(*stack_b) != 0)
		send_action("pa", stack_a, stack_b, 1);
	make_rotation(stack_a, stack_b, max);
}
