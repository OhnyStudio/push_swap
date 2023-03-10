/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:42:00 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/10 15:00:40 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_next_min_pos(t_push **b, t_stack *stack)
{
	t_push	*head_b;
	int		i;

	head_b = *b;
	i = 0;
	while (head_b)
	{
		if (head_b->index == stack->next_min)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

int	get_next_max_pos(t_push **b, t_stack *stack)
{
	t_push	*head_b;
	int		i;

	head_b = *b;
	i = 0;
	while (head_b)
	{
		if (head_b->index == stack->next_max)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

static void	send_correct_rrb(t_push **a, t_push **b, t_stack *stack)
{
	if ((stack->size_b - stack->min) < (stack->size_b - stack->max))
		send_actions_rrb_min(a, b, stack, stack->size_b - stack->min);
	else
		send_actions_rrb_max(a, b, stack, stack->size_b - stack->max);
}

static void	send_correct_rb(t_push **a, t_push **b, t_stack *stack)
{
	if (stack->min < stack->max)
		send_actions_rb_min(a, b, stack, stack->min);
	else
		send_actions_rb_max(a, b, stack, stack->max);
}

void	check_other_best(t_push **a, t_push **b, t_stack *stack)
{
	stack->min = get_next_min_pos(b, stack);
	stack->max = get_next_max_pos(b, stack);
	if (stack->min >= stack->size_b / 2 && stack->max >= stack->size_b / 2)
	{
		send_correct_rrb(a, b, stack);
	}
	else if (stack->min >= stack->size_b / 2)
	{
		if ((stack->size_b - stack->min) < stack->max)
			send_actions_rrb_min(a, b, stack, stack->size_b - stack->min);
		else
			send_actions_rb_max(a, b, stack, stack->max);
	}
	else if (stack->max >= stack->size_b / 2)
	{
		if (stack->min < (stack->size_b - stack->max))
			send_actions_rb_min(a, b, stack, stack->min);
		else
			send_actions_rrb_max(a, b, stack, stack->size_b - stack->max);
	}
	else
	{
		send_correct_rb(a, b, stack);
	}
}
