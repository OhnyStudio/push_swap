/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:12:40 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/10 20:21:52 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_push **stack_to, t_push **stack_from)
{
	t_push	*head_push;
	t_push	*next_push;

	if (stack_size(*stack_from) < 1)
		return (0);
	head_push = *stack_from;
	next_push = head_push->next;
	head_push->next = NULL;
	add_front_stack(stack_to, head_push);
	*stack_from = next_push;
	return (1);
}

static void	rotate(t_push **stack)
{
	t_push	*head;
	t_push	*tail;
	t_push	*tmp;

	head = *stack;
	*stack = (*stack)->next;
	tmp = head;
	while (tmp)
	{
		if (tmp->next == NULL)
			tail = tmp;
		tmp = tmp->next;
	}
	head->next = NULL;
	tail->next = head;
}

static void	rrotate(t_push **stack)
{
	t_push	*head;
	t_push	*before_tail;
	t_push	*tail;
	t_push	*tmp;

	head = *stack;
	tmp = head;
	tail = NULL;
	before_tail = NULL;
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			before_tail = tmp;
			tail = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	*stack = tail;
	(*stack)->next = head;
	before_tail->next = NULL;
}

static int	swap(t_push **stack)
{
	t_push	*head;
	t_push	*next;
	int		tmp_value;
	int		tmp_index;

	if (stack_size(*stack) < 2)
		return (0);
	head = *stack;
	next = head->next;
	tmp_value = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_value;
	next->index = tmp_index;
	return (1);
}

int	send_action(char *action, t_push **a, t_push **b, int is_print)
{
	if (ft_strcmp(action, "pa") == 0)
		return (push(a, b));
	if (ft_strcmp(action, "pb") == 0)
		return (push(b, a));
	if (ft_strcmp(action, "ra") == 0 || ft_strcmp(action, "rr") == 0)
		rotate(a);
	if (ft_strcmp(action, "rb") == 0 || ft_strcmp(action, "rr") == 0)
		rotate(b);
	if (ft_strcmp(action, "rra") == 0 || ft_strcmp(action, "rrr") == 0)
		rrotate(a);
	if (ft_strcmp(action, "rrb") == 0 || ft_strcmp(action, "rrr") == 0)
		rrotate(b);
	if (ft_strcmp(action, "sa") == 0 || ft_strcmp(action, "ss") == 0)
		return (swap(a));
	if (ft_strcmp(action, "sb") == 0 || ft_strcmp(action, "ss") == 0)
		return (swap(b));
	if (is_print != 0)
	{
		ft_putstr_fd(action, 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}
