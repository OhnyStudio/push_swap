/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_new_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:34 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/04 14:55:48 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	fit_in(int top, int down, int new, int is_reverse)
// {
// 	if (is_reverse == 1)
// 	{
// 		if (top > new && down < new)
// 			return (1);
// 	}
// 	else
// 	{
// 		if (top < new && down > new)
// 			return (1);
// 	}
// 	return (0);
// }

static int	fit_in_perfect(int top, int down, int new, int is_reverse)
{
	if (is_reverse == 1)
	{
		if (top == new + 1 && down == new - 1)
			return (1);
	}
	else
	{
		if (top == new - 1 && down == new + 1)
			return (1);
	}
	return (0);
}

static void	set_indexes(t_push **stack_a, t_push **stack_b, t_index *index)
{
	index->head_a = (*stack_a)->index;
	index->swap_a = (*stack_a)->next->index;
	index->tail_a = find_tail(stack_a, 1);
	index->head_b = (*stack_b)->index;
	index->swap_b = (*stack_b)->next->index;
	index->tail_b = find_tail(stack_b, 1);
}

static void	one_move(t_push **stack_a, t_push **stack_b)
{
	t_index	index;

	set_indexes(stack_a, stack_b, &index);
	if (fit_in_perfect(index.tail_b, index.head_b, index.head_a, 0) == 1)
		send_action("pb", stack_a, stack_b, 1);
	else if (fit_in_perfect(index.swap_b, (*stack_b)->next->next->index,
			index.head_b, 0) == 1)
		send_action("sb", stack_a, stack_b, 1);
	if (fit_in_perfect(index.head_a, index.tail_a, index.head_b, 0) == 1)
		send_action("pa", stack_a, stack_b, 1);
	else if (fit_in_perfect(index.swap_a, (*stack_a)->next->next->index,
			index.head_a, 0) == 1)
		send_action("sa", stack_a, stack_b, 1);
}

static void	two_move(t_push **stack_a, t_push **stack_b)
{
	//swap b fit in a
	//swap a fit in b
	//tail b fit in a
	//tail a fit in b
	(void)stack_a;
	(void)stack_b;
}

static void	three_move(t_push **stack_a, t_push **stack_b)
{
	//swap b fit in swap a
	//swap a fit in swap b
	//2 x rb in a
	//2 x ra in b
	//2 x rr in a
	//2 x rr in b
	//2 x rrb in a
	//2 x rra in b
	//2 x rrr in a
	//2 x rrr in b
	//2 x ra and swap a
	//2 x rb and swap b
	//2 x rra and swap a
	//2 x rrb and swap b
	(void)stack_a;
	(void)stack_b;
}

void	move_stacks(t_push **stack_a, t_push **stack_b)
{
	one_move(stack_a, stack_b);
	two_move(stack_a, stack_b);
	three_move(stack_a, stack_b);
}
