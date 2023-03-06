/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:27 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/06 17:56:08 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_double_action_a(t_push **a, t_push **b)
{
	send_action("pa", a, b, 1);
	send_action("ra", a, b, 1);
}

static char	*get_action_a(t_push **a, t_push **b, int index)
{
	char	*action;

	if (stack_size(*b) > 1)
	{
		if (other_smaller(index, find_tail(b, 0)) == 0)
			send_action("rrb", a, b, 1);
		else
		{
			if (other_smaller(index, (*b)->next->index) == 0)
				send_action("rb", a, b, 1);
		}
	}
	if (count_rotation(a, (*b)->index) < stack_size(*a) / 2)
		action = "ra";
	else
		action = "rra";
	return (action);
}

static int	check_insert_pos(t_push **a, t_push **b, int new_index)
{
	t_push	*head;
	int		i;

	head = *a;
	i = 0;
	while (head)
	{
		if (head->index == new_index + 1)
			return (i);
		else if (head->index == new_index - 1)
			return (++i);
		head = head->next;
		i++;
	}
}

void	swap_to_a(t_push **a, t_push **b, int size)
{
	t_push	*head;
	int		min;
	int		max;

	min = (*b)->index;
	max = (*b)->index;
	send_action("pa", a, b, 1);
	head = *b;
	(void)size;
	while (b)
	{
		if (head->index < min)
		{
			min = head->index;
			send_action("pa", a, b, 1);
		}
		else if (head->index > max)
		{
			max = head->index;
			send_double_action_a(a, b);
		}
		else
			check_insert_pos(a, b, head->index);
		head = *b;
	}
}
