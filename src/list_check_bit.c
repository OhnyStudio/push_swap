/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:26:22 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/07 19:39:23 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_bit(t_push **stack_a, t_push **stack_b, int n)
{
	int		size;

	size = stack_size(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index & (1 << n))
			send_action("ra", stack_a, stack_b, 1);
		else
			send_action("pb", stack_a, stack_b, 1);
	}
}
