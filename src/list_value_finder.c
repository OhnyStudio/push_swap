/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_value_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:56 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/08 11:07:04 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_push	**stack, int needindex)
{
	t_push	*head;
	t_push	*min_node;
	int		min;

	min = 2147483647;
	head = *stack;
	while (head)
	{
		if (needindex == 1 && head->index < min)
			min = head->index;
		else
		{
			if (head->value < min)
			{
				min = head->value;
				min_node = head;
			}
		}
		head = head->next;
	}
	if (needindex == 0)
		min_node->index = 1;
	return (min);
}

int	find_max(t_push	**stack, int needindex)
{
	t_push	*head;
	int		max;

	max = -2147483648;
	head = *stack;
	while (head)
	{
		if (needindex == 1)
		{
			if (head->index > max)
				max = head->index;
		}
		else
		{
			if (head->value > max)
				max = head->value;
		}
		head = head->next;
	}
	return (max);
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
