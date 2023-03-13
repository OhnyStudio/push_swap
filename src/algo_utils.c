/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:55:03 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/13 16:06:33 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ra_or_rra(t_push **stack, long max)
{
	t_push	*head;
	long	size;
	long	count;

	size = stack_size(*stack);
	count = 0;
	head = *stack;
	while (head)
	{
		if (head->value == max)
			break ;
		head = head->next;
		count++;
	}
	if (count >= size / 2)
		return (1);
	return (0);
}

void	min_to_top_4(t_push **stack_a, t_push **stack_b, long min)
{
	t_push	*head;
	long	count;

	head = *stack_a;
	count = 0;
	while (head)
	{
		if (head->index == min)
			break ;
		count++;
		head = head->next;
	}
	if (count == 1)
		send_action("sa", stack_a, stack_b, 1);
	else if (count == 2)
	{
		send_action("ra", stack_a, stack_b, 1);
		send_action("sa", stack_a, stack_b, 1);
	}
	else if (count == 3)
		send_action("rra", stack_a, stack_b, 1);
}

void	min_to_top_5(t_push **stack_a, t_push **stack_b, long min)
{
	t_push	*head;
	long	count;

	head = *stack_a;
	count = 0;
	while (head)
	{
		if (head->index == min)
			break ;
		count++;
		head = head->next;
	}
	if (count == 1)
		send_action("sa", stack_a, stack_b, 1);
	else if (count == 2)
	{
		send_action("ra", stack_a, stack_b, 1);
		send_action("sa", stack_a, stack_b, 1);
	}
	else if (count == 3)
	{
		send_actions("rra", stack_a, stack_b, 2);
	}
	else if (count == 4)
		send_action("rra", stack_a, stack_b, 1);
}

void	set_backward(t_push **stack_a, t_push **stack_b, long max)
{
	long	size;
	long	i;

	i = 0;
	size = stack_size(*stack_a);
	if (ra_or_rra(stack_a, max) == 0)
	{
		while ((*stack_a)->value != max)
			send_action("ra", stack_a, stack_b, 1);
	}
	else
	{
		while ((*stack_a)->value != max)
			send_action("rra", stack_a, stack_b, 1);
	}
	while (i < size - 1)
	{
		send_action("rra", stack_a, stack_b, 1);
		send_action("pb", stack_a, stack_b, 1);
		i++;
	}
	while (--i >= 0)
		send_action("pa", stack_a, stack_b, 1);
}

void	make_rotation(t_push **stack_a, t_push **stack_b, long max)
{
	if (ra_or_rra(stack_a, max) == 0)
	{
		while (is_sorted(stack_a) == 0)
			send_action("ra", stack_a, stack_b, 1);
	}
	else
	{
		while (is_sorted(stack_a) == 0)
			send_action("rra", stack_a, stack_b, 1);
	}
}
