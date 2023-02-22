/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_algo_complexe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:27 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/22 15:40:08 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_double_action(t_push **a, t_push **b)
{
	send_action("pb", a, b, 1);
	send_action("rb", a, b, 1);
}

void	swap_to_b(t_push **a, t_push **b, int size)
{
	t_push	*head;
	t_push	*tmp;
	int		min_max[2];

	min_max[0] = (*a)->value;
	min_max[1] = (*a)->value;
	send_action("pb", a, b, 1);
	head = *a;
	while (--size > 1)
	{
		tmp = head->next;
		if (head->value > min_max[1])
		{
			min_max[1] = head->value;
			send_action("pb", a, b, 1);
		}
		else if (head->value < min_max[0])
		{
			min_max[0] = head->value;
			send_double_action(a, b);
		}
		else
			send_action("ra", a, b, 1);
		head = tmp;
	}
}

static int	is_min_max(t_push **a, t_push **b, int min, int max)
{
	char	*action;

	if ((*a)->value == min)
	{
		if (ra_or_rra(b, find_max(b)) == 0)
			action = "rb";
		else
			action = "rrb";
		while ((*b)->value != find_min(b))
			send_action(action, a, b, 1);
		return (1);
	}
	else if ((*a)->value == max)
	{
		if (ra_or_rra(b, find_max(b)) == 0)
			action = "rrb";
		else
			action = "rb";
		while ((*b)->value != find_max(b))
			send_action(action, a, b, 1);
		return (1);
	}
	return (0);
}

static char	*get_action(t_push **a, t_push **b, int value)
{
	char	*action;

	if (stack_size(*a) > 1)
	{
		if (other_smaller(value, find_tail(a)) == 0)
			send_action("rra", a, b, 1);
		else
		{
			if (other_smaller(value, (*a)->next->value) == 0)
				send_action("ra", a, b, 1);
		}
	}
	if (count_rotation(b, (*a)->value) < stack_size(*b) / 2)
		action = "rb";
	else
		action = "rrb";
	return (action);
}

void	insert_to_b(t_push **a, t_push **b, int min, int max)
{
	t_push	*head_a;
	t_push	*head_b;
	char	*action;

	head_a = *a;
	head_b = *b;
	while (head_a)
	{
		if (is_min_max(a, b, min, max) == 0)
		{
			action = get_action(a, b, head_a->value);
			head_a = *a;
			while (head_a->value > find_tail(b)
				|| head_a->value < head_b->value)
			{
				send_action(action, a, b, 1);
				head_b = *b;
			}
		}
		send_action("pb", a, b, 1);
		head_a = *a;
		head_b = *b;
	}
}
