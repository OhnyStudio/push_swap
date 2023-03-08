/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:16:07 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/08 11:26:30 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	first_move(t_push **stack_a, int split, int need_moves)
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

static void	send_good_action(t_push **a, t_push **b, int current_split)
{
	int	rb;

	if (first_move(a, current_split, 0) == 0)
		send_actions("ra", a, b, first_move(a, current_split, 1));
	else
		send_actions("rra", a, b, first_move(a, current_split, 1));
	if (stack_size(*b) > 1)
	{
		rb = check_rb_rrb(b, (*a)->index);
		if (rb < stack_size(*b) - rb)
			send_actions("rb", a, b, rb);
		else
			send_actions("rrb", a, b, stack_size(*b) - rb);
	}
	send_action("pb", a, b, 1);
}

void	split_sort(t_push **a, t_push **b, int nb_split)
{
	int	origin_split;
	int	current_split;
	int	i;

	origin_split = stack_size(*a) / nb_split;
	current_split = origin_split;
	i = 0;
	while (stack_size(*a) > 0)
	{
		while (i < current_split)
		{
			if (stack_size(*a) == 0)
				break ;
			send_good_action(a, b, current_split);
			i++;
		}
		current_split += origin_split;
	}
}
