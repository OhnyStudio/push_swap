/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/08 23:14:47 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo2(t_push **stack)
{
	sa(stack);
}

void	algo3(t_push **stack_a, int min, int max)
{
	t_push	*head;

	head = *stack_a;
	if (head->next->next->value == max)
		sa(stack_a);
	else if (head->value == max)
	{
		if (head->next->value != min)
		{
			ra(stack_a);
			sa(stack_a);
		}
		else
			ra(stack_a);
	}
	else
	{
		if (head->value == min)
		{
			rra(stack_a);
			sa(stack_a);
		}
		else
			rra(stack_a);
	}
}

void	algo4(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	second_min;

	min_to_top(stack_a, min);
	pb(stack_b, stack_a);
	second_min = find_min(stack_a);
	algo3(stack_a, second_min, max);
	pa(stack_a, stack_b);
}
