/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:11:56 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/09 13:45:47 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_push **stack)
{
	t_push	*before_tail;
	t_push	*tail;
	t_push	*head;
	t_push	*tmp;

	head = *stack;
	tmp = head;
	tail = NULL;
	before_tail = NULL;
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			before_tail = tmp;
			tail = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	*stack = tail;
	(*stack)->next = head;
	before_tail->next = NULL;
}

void	rra(t_push **stack_a, int is_printing)
{
	rrotate(stack_a);
	if (is_printing != 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push **stack_b, int is_printing)
{
	rrotate(stack_b);
	if (is_printing != 0)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_push **stack_a, t_push **stack_b, int is_printing)
{
	rrotate(stack_a);
	rrotate(stack_b);
	if (is_printing != 0)
		ft_putstr_fd("rrr\n", 1);
}
