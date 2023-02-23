/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:26:22 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/23 16:06:58 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_bit(t_push **stack_a, t_push **stack_b, int n, int max)
{
	int		size;

	size = stack_size(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index & (1 << n))
			send_action("pb", stack_a, stack_b, 1);
		else
			send_action("ra", stack_a, stack_b, 1);
	}
	size = stack_size(*stack_b);
	n++;
	while (size--)
	{
		if ((*stack_b)->index & (1 << n))
			send_action("rb", stack_a, stack_b, 1);
		else
			send_action("pa", stack_a, stack_b, 1);
	}
	if (n < max + 1)
		check_bit(stack_a, stack_b, n, max);
}


int	find_max_bit(int index)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < 32)
	{
		if (index & (1 << i))
			max = i;
		i++;
	}
	return (max);
}
