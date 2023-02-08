/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:38:26 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/07 21:03:13 by johnysavard      ###   ########.fr       */
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
	(void)stack_a;
	(void)stack_b;
	ft_putstr_fd("Whille Sorts soon!\n", 1);
}
