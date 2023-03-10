/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:16:07 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/10 14:47:08 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_need_rb(t_push **a, t_push **b, t_stack *stack)
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
	if (i < stack->size_b / 2)
	{
		send_action("rr", a, b, 1);
		stack->possible_rb--;
		stack->possible_rrb++;
	}
	else
		send_action("ra", a, b, 1);
}

static void	set_stack_new_min(t_push **a, t_push **b, t_stack *stack, int i)
{
	if (i < stack->size_b / 2)
	{
		send_actions("rb", a, b, i);
		stack->possible_rb -= i;
		stack->possible_rrb += i;
		stack->next_min = (*b)->index - 1;
	}
	else
	{
		send_actions("rrb", a, b, stack->size_b - i);
		stack->possible_rb += i;
		stack->possible_rrb -= i;
		stack->next_min = (*b)->index - 1;
	}
}

static void	set_stack_new_max(t_push **a, t_push **b, t_stack *stack, int i)
{
	if (i < stack->size_b / 2)
	{
		send_actions("rb", a, b, i);
		stack->possible_rb -= i;
		stack->possible_rrb += i;
		stack->next_max = (*b)->index + 1;
	}
	else
	{
		send_actions("rrb", a, b, stack->size_b - i);
		stack->possible_rb += i;
		stack->possible_rrb -= i;
		stack->next_max = (*b)->index + 1;
	}
}

void	check_next_best(t_push **a, t_push **b, t_stack *stack)
{
	if (stack->next_max == -1)
	{
		set_stack_new_min(a, b, stack, get_next_min_pos(b, stack));
		stack_pa_update(a, b, stack);
	}
	else if (stack->next_min == -1)
	{
		set_stack_new_max(a, b, stack, get_next_max_pos(b, stack));
		stack_pa_update(a, b, stack);
		check_need_rb(a, b, stack);
	}
	else
	{
		check_other_best(a, b, stack);
		stack_pa_update(a, b, stack);
	}
}
