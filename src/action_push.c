/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:55:31 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/07 21:14:33 by johnysavard      ###   ########.fr       */
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

int	pa(t_push **stack_a, t_push **stack_b)
{
	if (stack_size(stack_b) < 1)
		return (0);
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_push **stack_b, t_push **stack_a)
{
	if (stack_size(stack_a) < 1)
		return (0);
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
	return (1);
}