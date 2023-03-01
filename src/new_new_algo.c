/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_new_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:34 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/01 14:51:38 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nb_ra(t_push **stack_a, int b_index)
{
	t_push	*head_a;
	int		closest_index;
	int		count;
	int		i;

	head_a = *stack_a;
	closest_index = stack_size(*stack_a);
	count = 0;
	i = 0;
	while (head_a)
	{
		if (head_a->index < closest_index && head_a->index > b_index)
		{
			closest_index = head_a->index;
			count = i;
		}
		head_a = head_a->next;
		i++;
	}
	return (count);
}

static int	nb_rra(t_push **stack_a, int b_index)
{
	int	size;
	int	rra;

	size = stack_size(*stack_a);
	rra = size - nb_ra(stack_a, b_index);
	return (rra);
}

static int	check_rr(int ra, int rb)
{
	if (ra > 0 && rb > 0)
	{
		if (ra < rb)
			return (ra);
		else
			return (rb);
	}
	return (0);
}

static int	check_rrr(int rra, int rrb)
{
	if (rra > 0 && rrb > 0)
	{
		if (rra < rrb)
			return (rra);
		else
			return (rrb);
	}
	return (0);
}

void	set_move(t_push **stack_a, t_push **stack_b)
{
	t_push	*head;
	int		i;

	head = *stack_b;
	i = 0;
	while (head)
	{
		head->move.ra = nb_ra(stack_a, head->index);
		head->move.rb = i++;
		head->move.rr = check_rr(head->move.ra, head->move.rb);
		head->move.ra -= head->move.rr;
		head->move.rb -= head->move.rr;
		head->move.rra = nb_rra(stack_a, head->index);
		head->move.rrb = stack_size(*stack_b) - i;
		head->move.rrr = check_rrr(head->move.rra, head->move.rrb);
		head->move.rra -= head->move.rrr;
		head->move.rrb -= head->move.rrr;
		head = head->next;
	}
	(void)stack_a;
}

void	move_weigth(t_push **stack_b)
{
	t_push	*head;
	int		r;
	int		rr;
	int		other[2];

	head = *stack_b;
	while (head)
	{
		r = head->move.ra + head->move.rb + head->move.rr;
		rr = head->move.rra + head->move.rrb + head->move.rrr;
		other[0] = head->move.ra + head->move.rrb;
		other[1] = head->move.rb + head->move.rra;
		if (r < rr && r < other[0] && r < other[1])
			head->move.nb_moves = r;
		else if (rr < r && rr < other[0] && rr < other[1])
			head->move.nb_moves = rr;
		else if (other[0] < r && other[0] < rr && other[0] < other[1])
			head->move.nb_moves = other[0];
		else if (other[1] < r && other[1] < rr && other[1] < other[0])
			head->move.nb_moves = other[1];
		head = head->next;
	}
}

char	*witch_action(t_push **stack_b, int count)
{
	t_push	*head;
	int		r;
	int		rr;
	int		other[2];

	head = *stack_b;
	while (count--)
	{
		head = head->next;
	}
	r = head->move.ra + head->move.rb + head->move.rr;
	rr = head->move.rra + head->move.rrb + head->move.rrr;
	other[0] = head->move.ra + head->move.rrb;
	other[1] = head->move.rb + head->move.rra;
	if (r < rr && r < other[0] && r < other[1])
		return ("r");
	else if (rr < r && rr < other[0] && rr < other[1])
		return ("rr");
	else if (other[0] < r && other[0] < rr && other[0] < other[1])
		return ("rarrb");
	else if (other[1] < r && other[1] < rr && other[1] < other[0])
		return ("rbrra");
	return ("pa");
}

void	split_stack_nb(t_push **stack_a, t_push **stack_b, int nb_split)
{
	long	split_origin;
	long	split_size;
	long	split_count;

	split_origin = stack_size(*stack_a) / nb_split;
	split_size = split_origin;
	split_count = 0;
	while (stack_size(*stack_a) > 0)
	{
		if ((*stack_a)->index <= split_size)
		{
			split_count++;
			send_action("pb", stack_a, stack_b, 1);
			if (split_count >= split_size)
				split_size += split_origin;
		}
		else
			send_action("ra", stack_a, stack_b, 1);
	}
}

int	check_smallest_move(t_push **stack_b)
{
	t_push	*head;
	int		smallest;
	int		i;

	head = *stack_b;
	i = 0;
	smallest = stack_size(*stack_b);
	while (head)
	{
		if (head->move.nb_moves < smallest)
			smallest = i;
		i++;
		head = head->next;
	}
	return (smallest);
}
