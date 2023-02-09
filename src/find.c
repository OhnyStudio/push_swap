/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:56 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/08 19:55:14 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_push	**stack)
{
	t_push	*head;
	int		min;

	min = 2147483647;
	head = *stack;
	while (head)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
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
			max = head->value;
		head = head->next;
	}
	return (max);
}
