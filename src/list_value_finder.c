/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_value_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:56 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/13 16:45:44 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	find_min(t_push	**stack, int needindex)
{
	t_push	*head;
	t_push	*min_node;
	long	min;

	min = 21474836470;
	head = *stack;
	while (head)
	{
		if (needindex == 1 && head->index < min)
			min = head->index;
		else if (needindex == 0 && head->value < min)
		{
				min = head->value;
				min_node = head;
		}
		head = head->next;
	}
	if (needindex == 0)
		min_node->index = 1;
	return (min);
}

long	find_max(t_push	**stack, int needindex)
{
	t_push	*head;
	long	max;

	max = -21474836481;
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

long	find_tail(t_push **stack, int needindex)
{
	t_push	*head;
	long	value;
	long	index;

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
