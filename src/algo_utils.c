/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:55:03 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/10 20:14:42 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_if_rotate(t_push **stack)
{
	t_push	*head;
	int		size;
	int		next_index;

	head = *stack;
	size = stack_size(*stack);
	while (head)
	{
		if (head->next != NULL)
		{
			next_index = head->next->index;
			if (head->index == size)
			{
				if (next_index != 1)
					return (0);
			}
			else
			{
				if (next_index != head->index + 1)
					return (0);
			}
		}
		head = head->next;
	}
	return (1);
}

int	find_if_backward(t_push **stack)
{
	t_push	*head;
	int		size;
	int		next_index;

	head = *stack;
	size = stack_size(*stack);
	while (head)
	{
		if (head->next != NULL)
		{
			next_index = head->next->index;
			if (head->index == 1)
			{
				if (next_index != size)
					return (0);
			}
			else
			{
				if (next_index != head->index - 1)
					return (0);
			}
		}
		head = head->next;
	}
	return (1);
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
