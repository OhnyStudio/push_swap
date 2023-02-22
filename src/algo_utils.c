/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:55:03 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/22 15:42:58 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_or_rra(t_push **stack, int max)
{
	t_push	*head;
	int		size;
	int		count;

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

void	split_median(t_push **stack_a, t_push **stack_b)
{
	t_push	*head;
	t_push	*tmp;
	int		median;
	int		size;

	median = find_median(stack_a);
	head = *stack_a;
	size = stack_size(*stack_a);
	while (size--)
	{
		if (head->value > median)
		{
			tmp = head->next;
			send_action("pb", stack_a, stack_b, 1);
			head = tmp;
		}
		else
		{
			send_action("ra", stack_a, stack_b, 1);
			head = *stack_a;
		}
	}
}

void	min_to_top(t_push **stack_a, t_push **stack_b, int min)
{
	t_push	*head;
	int		count;

	head = *stack_a;
	count = 0;
	while (head)
	{
		if (head->value == min)
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

void	set_backward(t_push **stack_a, t_push **stack_b, int max)
{
	int		size;
	int		i;

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

void	make_rotation(t_push **stack_a, t_push **stack_b, int max)
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
