/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:39 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/10 14:35:24 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_stack_moves(t_stack *stack, int i, int new_index)
{
	stack->possible_rb -= i;
	stack->possible_rrb += i;
	stack->next_max = -1;
	stack->next_min = new_index;
}

static int	get_move_pos(t_push **b)
{
	t_push	*head_b;
	int		i;

	head_b = *b;
	i = 0;
	while (head_b)
	{
		if (head_b->index == find_max(b, 1))
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

void	check_first_best(t_push **a, t_push **b, t_stack *stack)
{	
	int		i;

	i = get_move_pos(b);
	if (i < stack->possible_rb / 2)
	{
		send_actions("rb", a, b, i);
		set_stack_moves(stack, i, (*b)->index - 1);
	}
	else
	{
		if (find_min(b, 1) == (*b)->index)
			stack->next_min = -1;
		else
			stack->next_min = (*b)->index - 1;
		stack->next_max = (*b)->index + 1;
	}
	stack_pa_update(a, b, stack);
}
