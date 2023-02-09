/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:35:53 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/09 14:10:28 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo2(t_push **stack)
{
	sa(stack, 1);
}

void	algo3(t_push **stack_a, int min, int max)
{
	t_push	*head;

	head = *stack_a;
	if (head->next->next->value == max)
		sa(stack_a, 1);
	else if (head->value == max)
	{
		if (head->next->value != min)
		{
			ra(stack_a, 1);
			sa(stack_a, 1);
		}
		else
			ra(stack_a, 1);
	}
	else
	{
		if (head->value == min)
		{
			rra(stack_a, 1);
			sa(stack_a, 1);
		}
		else
			rra(stack_a, 1);
	}
}

void	algo4(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	second_min;

	min_to_top(stack_a, min);
	pb(stack_b, stack_a, 1);
	second_min = find_min(stack_a);
	algo3(stack_a, second_min, max);
	pa(stack_a, stack_b, 1);
}

void	algo_other(t_push **stack_a, t_push **stack_b, int min, int max)
{
	//check if ra or rra work
	//size / 2 ra or size / 2 rra
	int	size;
	int	i;

	size = stack_size(stack_a);
	i = 0;
	while (i < size / 2 + 1)
	{
		ra(stack_a, 0);
		if (is_sorted(stack_a) != 0)
		{
			break ;
		}
		i++;
	}
}
