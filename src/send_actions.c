/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:48:45 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/08 10:35:14 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_actions_print(char *actions, t_push **a, t_push **b, int count)
{
	while (count--)
		send_action(actions, a, b, 1);
}

void	send_actions_no_print(char *actions, t_push **a, t_push **b, int count)
{
	while (count--)
		send_action(actions, a, b, 1);
}

void	send_action_ra(t_push **a, t_push **b, int ra, int rb)
{
	int	rr;
	int	rrb;

	rrb = stack_size(*b) - rb;
	if (rb < rrb)
	{
		if (ra < rb)
		rr = ra;
		else
			rr = rb;
		ra -= rr;
		rb -= rr;
		send_actions_print("rr", a, b, rr);
		send_actions_print("ra", a, b, ra);
		send_actions_print("rb", a, b, rb);
	}
	else
	{
		send_actions_print("ra", a, b, ra);
		send_actions_print("rrb", a, b, rrb);
	}
}

void	send_action_rra(t_push **a, t_push **b, int rra, int rb)
{
	int	rrr;
	int	rrb;

	rrb = stack_size(*b) - rb;
	if (rrb < rb)
	{
		if (rra < rrb)
		rrr = rra;
		else
			rrr = rrb;
		rra -= rrr;
		rrb -= rrr;
		send_actions_print("rrr", a, b, rrr);
		send_actions_print("rra", a, b, rra);
		send_actions_print("rrb", a, b, rrb);
	}
	else
	{
		send_actions_print("rb", a, b, rb);
		send_actions_print("rra", a, b, rra);
	}
}
