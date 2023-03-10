/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:45:03 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/10 14:34:26 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_pa_update(t_push **a, t_push **b, t_stack *stack)
{
	send_action("pa", a, b, 1);
	stack->size_a++;
	stack->size_b--;
	stack->possible_rb--;
}

static void	set_stack(t_push **a, t_push **b, t_stack *stack, int split)
{
	t_push	*head_b;
	int		i;

	head_b = *b;
	i = 0;
	while (head_b)
	{
		if (head_b->split == split)
			i++;
		head_b = head_b->next;
	}
	stack->possible_rb = i;
	stack->possible_rrb = 0;
	stack->size_a = stack_size(*a);
	stack->size_b = stack_size(*b);
}

static void	move_top_stack(t_push **a, t_push **b, int split)
{
	t_stack	stack;

	set_stack(a, b, &stack, split);
	check_first_best(a, b, &stack);
	while (stack_size(*b) > 1)
	{
		check_next_best(a, b, &stack);
	}
	send_action("pa", a, b, 1);
}

void	big_algo(t_push **stack_a, t_push **stack_b, int min, int max)
{
	int	origin_split;
	int	split;
	int	nb_split;

	(void)min;
	set_index(stack_a, find_min(stack_a, 0), 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
	{
		nb_split = 5;
		origin_split = stack_size(*stack_a) / nb_split;
		split = split_nb(stack_a, stack_b, origin_split);
		move_top_stack(stack_a, stack_b, split);
	}
}
