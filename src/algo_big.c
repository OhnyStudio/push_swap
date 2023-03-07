/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:45:03 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/07 16:53:41 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_stack_b(t_push **stack_a, t_push **stack_b)
{
	if (stack_size(*stack_b) > 1)
	{
		if ((*stack_b)->index > (*stack_b)->next->index)
			send_action("sb", stack_a, stack_b, 1);
	}
}

void	split_stack_nb(t_push **stack_a, t_push **stack_b, int nb_split, int i)
{
	long	split_origin;
	long	split_size;
	long	split_count;
	int		count;

	split_origin = stack_size(*stack_a) / nb_split;
	split_size = split_origin;
	split_count = 0;
	if (i == 1)
		count = split_origin;
	else
		count = 0;
	while (stack_size(*stack_a) > count)
	{
		if ((*stack_a)->index <= split_size)
		{
			split_count++;
			send_action("pb", stack_a, stack_b, 1);
			check_stack_b(stack_a, stack_b);
			if (split_count >= split_size)
				split_size += split_origin;
		}
		else
			send_action("ra", stack_a, stack_b, 1);
	}
}

// static void	split_stack_max(t_push **stack_a, t_push **stack_b, int nb_split)
// {
// 	long	split_origin;
// 	long	split_size;
// 	long	split_count;
// 	int		count;

// 	split_origin = stack_size(*stack_a) / nb_split;
// 	split_size = split_origin;
// 	split_count = 0;
// 	count = 0;
// 	while (stack_size(*stack_a) > count)
// 	{
// 		if ((*stack_a)->index == find_max(stack_a, 1) && count != 1)
// 		{
// 			count++;
// 			if ((*stack_a)->index <= split_size)
// 				split_count++;
// 			send_action("ra", stack_a, stack_b, 1);
// 		}
// 		else if ((*stack_a)->index <= split_size)
// 		{
// 			split_count++;
// 			send_action("pb", stack_a, stack_b, 1);
// 			if (split_count >= split_size)
// 				split_size += split_origin;
// 		}
// 		else
// 			send_action("ra", stack_a, stack_b, 1);
// 	}
// }

// static int	rb_or_rrb(t_push **stack, int min, int max, int need_count)
// {
// 	t_push	*head;
// 	int		count;

// 	count = 0;
// 	head = *stack;
// 	while (head)
// 	{
// 		if (head->index == min - 1)
// 			break ;
// 		else if (head->index == max + 1)
// 			break ;
// 		head = head->next;
// 		count++;
// 	}
// 	if (count >= stack_size(*stack) / 2)
// 	{
// 		if (need_count == 1)
// 			return (stack_size(*stack) - count);
// 		else
// 			return (1);
// 	}
// 	if (need_count == 1)
// 		return (count);
// 	else
// 		return (0);
// }

// static void	calcul_best_move(t_push **a, t_push **b, int min, int max)
// {
// 	if ((*b)->next->index == min - 1 && rb_or_rrb(b, min, max, 1) > 2)
// 	{
// 		send_action("sb", a, b, 1);
// 		send_action("pa", a, b, 1);
// 	}
// 	else if ((*b)->next->index == max + 1 && rb_or_rrb(b, min, max, 1) > 3)
// 	{
// 		send_action("sb", a, b, 1);
// 		send_action("pa", a, b, 1);
// 		send_action("ra", a, b, 1);
// 	}
// 	else
// 	{
// 		if (rb_or_rrb(b, min, max, 0) == 0)
// 			send_actions_print("rb", a, b, rb_or_rrb(b, min, max, 1));
// 		else
// 			send_actions_print("rrb", a, b, rb_or_rrb(b, min, max, 1));
// 	}
// }

// static void	insert_min_max(t_push **stack_a, t_push **stack_b)
// {
// 	int	new_min;
// 	int	new_max;

// 	new_min = find_min(stack_a, 1);
// 	new_max = find_max(stack_a, 1);
// 	while (stack_size(*stack_b) > 0)
// 	{
// 		if ((*stack_b)->index == new_min - 1)
// 		{
// 			new_min = (*stack_b)->index;
// 			send_action("pa", stack_a, stack_b, 1);
// 		}
// 		else if ((*stack_b)->index == new_max + 1)
// 		{
// 			new_max = (*stack_b)->index;
// 			send_action("pa", stack_a, stack_b, 1);
// 			send_action("ra", stack_a, stack_b, 1);
// 		}
// 		else
// 		{
// 			calcul_best_move(stack_a, stack_b, new_min, new_max);
// 		}
// 	}
// }

static int	ra_or_rra_2(t_push **stack_a, int new_index, int need_count)
{
	t_push	*head_a;
	int		count;

	count = 0;
	while (head_a)
	{
		if (head_a->index == new_index - 1)
			break ;
		head_a = head_a->next;
		count++;
	}
	if (count >= stack_size(*stack_a))
	{
		if (need_count == 1)
			return (stack_size(*stack_a) - count);
		else
			return (1);
	}
	else
	{
		if (need_count == 1)
			return (count);
		else
			return (0);
	}
}

static void	best_move(int *ra, int *rra,  t_push **stack_a, t_push **stack_b)
{
	int	i;
	int	rrb;
	int	rr;
	int	rrr;

	i = 0;
	while (ra[i])
	{
		if (i < stack_size(*stack_b) / 2)
		{
			if (ra[i] < i)
				rr = ra[i];
			else
				rr = i;
			if ((ra[i] - rr) + (i - rr) + rr < i + rra[i] && )
			{
				//ra + rb + rr
			}
			else
			{
				//rra + rb
			}
		}
		else
		{
			rrb = stack_size(*stack_b) - i;
			if (rra[i] < rrb)
				rrr = rra[i];
			else
				rrr = rrb;
			if ((rra[i] - rrr) + (rrb - rrr) + rrr < ra[i] + rrb)
			{
				
			}
			else
			{
				 
			}
		}
	}
}

static void	rb_or_rrb(t_push **stack_a, t_push **stack_b)
{
	t_push	*head_b;
	int		i;
	int		*ra;
	int		*rra;

	head_b = *stack_b;
	i = 0;
	while (head_b)
	{
		ra[i] = ra_or_rra_2(stack_a, head_b->index, 1);
		rra[i] = stack_size(*stack_a) - ra_or_rra_2(stack_a, head_b->index, 1);
		head_b = head_b->next;
		i++;
	}
}

static void	double_move(t_push **stack_a, t_push **stack_b)
{
	if ((*stack_a)->index == (*stack_b)->index + 1)
		send_action("pa", stack_a, stack_b, 1);
	else if ((*stack_a)->index == (*stack_b)->index - 1)
	{
		send_action("pa", stack_a, stack_b, 1);
		send_action("ra", stack_a, stack_b, 1);
	}
	else if ((*stack_a)->next->index == (*stack_b)->next->index + 1)
	{
		send_action("ss", stack_a, stack_b, 1);
		send_action("pa", stack_a, stack_b, 1);
	}	
	else if ((*stack_a)->next->index == (*stack_b)->next->index - 1)
	{
		send_action("ss", stack_a, stack_b, 1);
		send_action("pa", stack_a, stack_b, 1);
		send_action("ra", stack_a, stack_b, 1);
	}
	else
	{
		other_moves(stack_a, stack_a);
	}
}

void	big_algo(t_push **stack_a, t_push **stack_b, int min, int max)
{
	set_index(stack_a, min, 2);
	set_current_index(stack_a);
	if (find_if_rotate(stack_a) != 0)
		make_rotation(stack_a, stack_b, max);
	else if (find_if_backward(stack_a) != 0)
		set_backward(stack_a, stack_b, max);
	else
	{
		// if (stack_size(*stack_a) < 50)
		// 	split_stack_max(stack_a, stack_b, 2);
		// if (stack_size(*stack_a) < 250)
		// 	split_stack_max(stack_a, stack_b, 6);
		// else
		// 	split_stack_max(stack_a, stack_b, 9);
		// insert_min_max(stack_a, stack_b);
		check_bit(stack_a, stack_b, 0);
		double_move(stack_a, stack_b);
	}
}
