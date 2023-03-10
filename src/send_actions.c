/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:48:45 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/10 14:25:29 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_actions(char *actions, t_push **a, t_push **b, int count)
{
	while (count--)
		send_action(actions, a, b, 1);
}

void	send_actions_rb_min(t_push **a, t_push **b, t_stack *stack, int i)
{
	send_actions("rb", a, b, stack->size_b - i);
	stack->possible_rb += i;
	stack->possible_rrb -= i;
	stack->next_min = (*b)->index - 1;
}

void	send_actions_rrb_min(t_push **a, t_push **b, t_stack *stack, int i)
{
	send_actions("rrb", a, b, stack->size_b - i);
	stack->possible_rb += i;
	stack->possible_rrb -= i;
	stack->next_min = (*b)->index - 1;
}

void	send_actions_rb_max(t_push **a, t_push **b, t_stack *stack, int j)
{
	send_actions("rb", a, b, j);
	stack->possible_rb -= j;
	stack->possible_rrb += j;
	stack->next_max = (*b)->index + 1;
}

void	send_actions_rrb_max(t_push **a, t_push **b, t_stack *stack, int j)
{
	send_actions("rrb", a, b, j);
	stack->possible_rb -= j;
	stack->possible_rrb += j;
	stack->next_max = (*b)->index + 1;
}
