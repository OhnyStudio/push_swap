/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:56 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/11 11:13:03 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_push	**stack)
{
	t_push	*head;
	t_push	*min_node;
	int		min;

	min = 2147483647;
	head = *stack;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			min_node = head;
		}
		head = head->next;
	}
	min_node->index = 1;
	return (min);
}

int	find_max(t_push	**stack)
{
	t_push	*head;
	int		max;

	max = -2147483648;
	head = *stack;
	while (head)
	{
		if (head->value > max)
		{
			max = head->value;
		}
		head = head->next;
	}
	return (max);
}

void	set_index(t_push **stack, int current_min, int index)
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
	if (new_min != find_max(stack))
		set_index(stack, new_min, ++index);
}

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
