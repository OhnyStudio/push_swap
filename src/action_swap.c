/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:26:05 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/07 20:54:48 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_push **stack)
{
	t_push	*head;
	t_push	*next;
	int		tmp_value;
	int		tmp_index;

	head = *stack;
	next = head->next;
	tmp_value = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_value;
	next->index = tmp_index;
}

int	sa(t_push **stack_a)
{
	if (stack_size(*stack_a) < 2)
		return (0);
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
	return (1);
}

int	sb(t_push **stack_b)
{
	if (stack_size(*stack_b) < 2)
		return (0);
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
	return (1);
}

int	ss(t_push **stack_a, t_push **stack_b)
{
	if (stack_size(*stack_a) < 2 || stack_size(*stack_b) < 2)
		return (0);
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	return (1);
}
