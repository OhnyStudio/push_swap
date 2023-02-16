/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:05:07 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/16 15:58:18 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_median(t_push **stack_a, t_push **stack_b)
{
	t_push	*head;
	t_push	*tmp;
	int		median;
	int		size;

	median = find_median(stack_a);
	head = *stack_a;
	size = stack_size(*stack_a);
	while (size--)
	{
		if (head->value > median)
		{
			tmp = head->next;
			send_action("pb", stack_a, stack_b, 1);
			head = tmp;
		}
		else
		{
			send_action("ra", stack_a, stack_b, 1);
			head = *stack_a;
		}
	}
}

//Bigger than tail and small than head
//Count rb if rb count > size / 2

int	find_median(t_push **stack)
{
	t_push	*head;
	int		index_median;

	head = *stack;
	index_median = stack_size(*stack) / 2 + 1;
	while (head)
	{
		if (head->index == index_median)
			return (head->value);
		head = head->next;
	}
	return (0);
}

int	find_tail(t_push **stack)
{
	t_push	*head;
	int		value;

	head = *stack;
	value = 0;
	while (head)
	{
		value = head->value;
		head = head->next;
	}
	return (value);
}

void	ft_print_list(t_push **a)
{
	t_push	*temp;

	temp = (t_push *)malloc(sizeof(t_push));
	temp = *a;
	while (temp)
	{
		ft_putnbr_fd(temp->value, 1);
		ft_putstr_fd(" index: ", 1);
		ft_putnbr_fd(temp->index, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

int	count_rotation(t_push **stack, int value)
{
	t_push	*head;
	int		count;
	int		real_count;
	int		min_max[2];

	head = *stack;
	count = 0;
	real_count = 0;
	min_max[0] = find_min(stack);
	min_max[1] = find_max(stack);
	while (head)
	{
		if (head->next != NULL && head->value > value
			&& head->next->value < value && head->value < min_max[1]
			&& head->next->value > min_max[0])
		{
			min_max[1] = head->value;
			min_max[0] = head->next->value;
			real_count = count;
		}
		count++;
		head = head->next;
	}
	return (real_count);
}

int	other_smaller(int value, int other_value)
{
	if (value > other_value)
		return (1);
	return (0);
}
