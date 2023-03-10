/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:01:29 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/10 13:54:06 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_bad_split(t_push **stack_a)
{
	t_push	*head_a;

	head_a = *stack_a;
	head_a->split_ra = stack_size(*stack_a) * 2;
	head_a->split_rra = stack_size(*stack_a) * 2;
	head_a->ra_best = 2;
	head_a->split = 0;
}

static void	set_split(t_push **a, int current_split, int split)
{
	t_push	*head_a;
	int		i;

	head_a = *a;
	i = 0;
	while (head_a)
	{
		if (head_a->index <= current_split)
		{
			head_a->split_ra = i;
			head_a->split_rra = stack_size(*a) - i;
			if (head_a->split_ra < head_a->split_rra)
				head_a->ra_best = 1;
			else
				head_a->ra_best = 0;
			head_a->split = split;
		}
		else
		{
			set_bad_split(a);
		}
		(void)split;
		head_a = head_a->next;
		i++;
	}
}

static int	find_best(t_push **a)
{
	t_push	*head_a;
	int		i;
	int		best;
	int		save_i;

	head_a = *a;
	i = 0;
	save_i = 0;
	best = stack_size(*a);
	while (head_a)
	{
		if (head_a->ra_best == 1 && head_a->split_ra < best)
		{
			best = head_a->split_ra;
			save_i = i;
		}
		else if (head_a->ra_best == 0 && head_a->split_rra < best)
		{
			best = head_a->split_rra;
			save_i = i;
		}
		head_a = head_a->next;
		i++;
	}
	return (save_i);
}

int	split_nb(t_push **a, t_push **b, int origin_split)
{
	t_push	*head_a;
	int		current_split;
	int		i[3];

	current_split = origin_split;
	i[1] = 1;
	i[2] = 0;
	while (stack_size(*a) > 0)
	{
		set_split(a, current_split, i[1]);
		i[0] = find_best(a);
		head_a = *a;
		while (i[0]--)
			head_a = head_a->next;
		if (head_a->ra_best == 1)
			send_actions("ra", a, b, head_a->split_ra);
		else if (head_a->ra_best == 0)
			send_actions("rra", a, b, head_a->split_rra);
		send_action("pb", a, b, 1);
		i[2]++;
		if (i[2] == current_split)
			current_split += origin_split;
	}
	return (i[1]);
}
