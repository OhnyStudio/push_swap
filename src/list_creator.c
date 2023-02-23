/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:59:09 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/23 16:17:21 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_push	*stack_last(t_push *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_current_index(t_push **stack)
{
	t_push	*head;
	int		i;

	head = *stack;
	i = 1;
	while (head)
	{
		head->current_index = i;
		i++;
		head = head->next;
	}
}

void	add_back_stack(t_push **stack, t_push *new)
{
	t_push	*last;

	if (stack)
	{
		if (*stack)
		{
			last = stack_last(*stack);
			last->next = new;
		}
		else
			*stack = new;
	}
}

void	add_front_stack(t_push **stack, t_push *new)
{
	if (stack)
	{
		if (*stack)
			new->next = *stack;
		*stack = new;
	}
}

void	set_index(t_push **stack, int current_min, long index)
{
	t_push	*head;
	t_push	*min_node;
	int		new_min;

	head = *stack;
	new_min = 2147483647;
	while (head)
	{
		if (head->value < new_min && head->value > current_min)
		{
			min_node = head;
			new_min = head->value;
		}
		head = head->next;
	}
	min_node->index = index;
	if (new_min != find_max(stack, 0))
		set_index(stack, new_min, ++index);
}
