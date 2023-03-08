/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:16:07 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/08 10:36:44 by johnysavard      ###   ########.fr       */
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

static int	count_top_max(t_push **stack_b)
{
	t_push	*head_b;
	int		i;

	i = 0;
	head_b = *stack_b;
	while (head_b)
	{
		if (head_b->index == find_max(stack_b, 1))
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

static int	check_rb_rrb(t_push **stack_b, int new_index)
{
	t_push	*head_b;
	int		i;

	head_b = *stack_b;
	i = 0;
	if (new_index < find_min(stack_b, 1) || new_index > find_max(stack_b, 1))
		i = count_top_max(stack_b);
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

void	split_sort(t_push **stack_a, t_push **stack_b, int nb_split)
{
	int	origin_split;
	int	current_split;
	int	i;

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
				if (stack_size(*stack_b) > 1)
					send_action_ra(stack_a, stack_b,
						find_first_second(stack_a, current_split, 1),
						check_rb_rrb(stack_b, (*stack_a)->index));
				else
					send_action_ra(stack_a, stack_b,
						find_first_second(stack_a, current_split, 1), 0);
			}
			else
			{
				if (stack_size(*stack_b) > 1)
					send_action_rra(stack_a, stack_b,
						find_first_second(stack_a, current_split, 1),
						check_rb_rrb(stack_b, (*stack_a)->index));
				else
					send_action_rra(stack_a, stack_b,
						find_first_second(stack_a, current_split, 1), 0);
			}
			send_action("pb", stack_a, stack_b, 1);
			i++;
		}
		current_split += origin_split;
	}
}
