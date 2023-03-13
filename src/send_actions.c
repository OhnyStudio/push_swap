/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:48:45 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/13 16:08:24 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_actions(char *actions, t_push **a, t_push **b, long count)
{
	while (count--)
		send_action(actions, a, b, 1);
}

void	free_list(t_push **stack)
{
	t_push	*temp;

	while (stack && *stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(stack);
}
