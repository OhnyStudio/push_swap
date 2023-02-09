/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:55:31 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/09 13:43:30 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_push **stack_to, t_push **stack_from)
{
	t_push	*head_push;
	t_push	*next_push;

	head_push = *stack_from;
	next_push = head_push->next;
	head_push->next = NULL;
	add_front_stack(stack_to, head_push);
	*stack_from = next_push;
}

int	pa(t_push **stack_a, t_push **stack_b, int is_printing)
{
	if (stack_size(*stack_b) < 1)
		return (0);
	push(stack_a, stack_b);
	if (is_printing != 0)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_push **stack_b, t_push **stack_a, int is_printing)
{
	if (stack_size(*stack_a) < 1)
		return (0);
	push(stack_b, stack_a);
	if (is_printing != 0)
		ft_putstr_fd("pb\n", 1);
	return (1);
}