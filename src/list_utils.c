/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:59:09 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/11 11:19:50 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_push	*stack_last(t_push *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_push	*create_new_node(int value)
{
	t_push	*new_list;

	new_list = (t_push *)malloc(sizeof(t_push));
	if (!new_list)
		return (NULL);
	new_list->value = value;
	new_list->next = NULL;
	return (new_list);
}

void	add_back_stack(t_push **stack, t_push *new)
{
	t_push	*last;

	if (stack)
	{
		if (*stack)
		{
			last = stack_last(*stack);
			last->next = new;
		}
		else
			*stack = new;
	}
}

void	add_front_stack(t_push **stack, t_push *new)
{
	if (stack)
	{
		if (*stack)
			new->next = *stack;
		*stack = new;
	}
}

void	sort_stack(t_push **stack_a, t_push **stack_b)
{
	int	size;
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	size = stack_size(*stack_a);
	if (size == 2)
		algo2(stack_a, stack_b);
	else if (size == 3)
		algo3(stack_a, stack_b, min, max);
	else if (size == 4)
		algo4(stack_a, stack_b, min, max);
	else if (size > 4)
		algo_other(stack_a, stack_b, min, max);
	(void)stack_b;
	(void)stack_a;
}