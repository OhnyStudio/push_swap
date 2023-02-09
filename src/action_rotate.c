/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:21:38 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/08 19:11:23 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_push **stack)
{
	t_push	*head;
	t_push	*tail;
	t_push	*tmp;

	head = *stack;
	*stack = (*stack)->next;
	tmp = head;
	while (tmp)
	{
		if (tmp->next == NULL)
			tail = tmp;
		tmp = tmp->next;
	}
	head->next = NULL;
	tail->next = head;
}

void	ra(t_push **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_push **stack_a, t_push **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
