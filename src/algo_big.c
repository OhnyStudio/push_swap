/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:45:03 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/08 10:12:04 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_first_second(t_push **stack_a, int split, int need_moves)
{
	t_push	*head_a;
	int		first_nbs[2];
	int		i;

	head_a = *stack_a;
	first_nbs[0] = 0;
	first_nbs[1] = 0;
	i = 0;
	while (head_a)
	{
		if (head_a->index < split && first_nbs[0] == 0)
			first_nbs[0] = i;
		if (head_a->index < split && head_a->index != first_nbs[0])
			first_nbs[1] = stack_size(*stack_a) - i;
		head_a = head_a->next;
		i++;
	}
	if (first_nbs[0] < first_nbs[1] && need_moves == 1)
		return (first_nbs[0]);
	else if (first_nbs[0] < first_nbs[1] && need_moves == 0)
		return (0);
	else if (first_nbs[0] > first_nbs[1] && need_moves == 1)
		return (first_nbs[1]);
	else
		return (1);
}

static int	check_rb_rrb(t_push **stack_b, int new_index)
{
	t_push	*head_b;
	int		i;

	head_b = *stack_b;
	i = 0;
	if (new_index < find_min(stack_b, 1) || new_index > find_max(stack_b, 1))
	{
		while (head_b)
		{
			if (head_b->index == find_max(stack_b, 1))
				break ;
			head_b = head_b->next;
			i++;
		}
	}
	else
	{
		if (new_index > head_b->index && new_index < find_tail(stack_b, 1))
			return (0);
		else
		{
			i = 1;
			while (head_b)
			{
				if (head_b->index > new_index
					&& head_b->next->index < new_index)
					break ;
				head_b = head_b->next;
				i++;
			}
		}	
	}
	return (i);
}

static void	max_to_top(t_push **stack_a, t_push **stack_b)
{
	t_push	*head_b;
	int		max;

	max = find_max(stack_b, 1);
	head_b = *stack_b;
	while (head_b->index != max)
	{
		send_action("rb", stack_a, stack_b, 1);
		head_b = *stack_b;
	}
}

static void	split_sort(t_push **stack_a, t_push **stack_b, int nb_split)
{
	int	origin_split;
	int	current_split;
	int	i;
	int	rb;

	origin_split = stack_size(*stack_a) / nb_split;
	current_split = origin_split;
	i = 0;
	while (stack_size(*stack_a) > 0)
	{
		while (i < current_split)
		{
			if (stack_size(*stack_a) == 0)
				break ;
			if (find_first_second(stack_a, current_split, 0) == 0)
			{
				//ra
				send_actions_print("ra", stack_a, stack_b,
					find_first_second(stack_a, current_split, 1));
			}
			else
			{
				//rra
				send_actions_print("rra", stack_a, stack_b,
					find_first_second(stack_a, current_split, 1));
			}
			if (stack_size(*stack_b) > 1)
			{
				rb = check_rb_rrb(stack_b, (*stack_a)->index);
				if (rb < stack_size(*stack_b) - rb)
					send_actions_print("rb", stack_a, stack_b, rb);
				else
					send_actions_print("rrb", stack_a, stack_b,
						stack_size(*stack_b) - rb);
			}
			send_action("pb", stack_a, stack_b, 1);
			i++;
		}
		current_split += origin_split;
	}
}

void	big_algo(t_push **stack_a, t_push **stack_b, int min, int max)
{
	(void)min;
	set_index(stack_a, find_min(stack_a, 0), 2);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
	{
		split_sort(stack_a, stack_b, 5);
		max_to_top(stack_a, stack_b);
		while (stack_size(*stack_b) > 0)
			send_action("pa", stack_a, stack_b, 1);
	}
}
