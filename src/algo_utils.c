/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:55:03 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/08 23:14:36 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_push **stack, int min)
{
	t_push	*head;
	int		count;

	head = *stack;
	count = 0;
	while (head)
	{
		if (head->value == min)
			break ;
		count++;
		head = head->next;
	}
	if (count == 1)
		sa(stack);
	else if (count == 2)
	{
		ra(stack);
		sa(stack);
	}
	else if (count == 3)
		rra(stack);
}