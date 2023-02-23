/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_value_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:56 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/23 14:54:23 by jsavard          ###   ########.fr       */
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

int	find_max(t_push	**stack, int needindex)
{
	t_push	*head;
	int		max;
	int		index;

	max = -2147483648;
	index = 0;
	head = *stack;
	while (head)
	{
		if (head->value > max)
		{
			max = head->value;
			index = head->index;
		}
		head = head->next;
	}
	if (needindex == 0)
		return (max);
	else
		return (index);
}

int	find_tail(t_push **stack, int needindex)
{
	t_push	*head;
	int		value;
	int		index;

	head = *stack;
	value = 0;
	index = 0;
	while (head)
	{
		value = head->value;
		index = head->index;
		head = head->next;
	}
	if (needindex == 0)
		return (value);
	else
		return (index);
}

int	find_median(t_push **stack)
{
	t_push	*head;
	int		index_median;

	head = *stack;
	index_median = stack_size(*stack) / 2 + 1;
	while (head)
	{
		if (head->index == index_median)
			return (head->value);
		head = head->next;
	}
	return (0);
}
