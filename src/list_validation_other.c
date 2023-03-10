/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_validation_other.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:05:07 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/13 16:08:08 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	find_if_rotate(t_push **stack)
{
	t_push	*head;
	long	size;
	long	next_index;

	head = *stack;
	size = stack_size(*stack);
	while (head)
	{
		if (head->next != NULL)
		{
			next_index = head->next->index;
			if (head->index == size)
			{
				if (next_index != 1)
					return (0);
			}
			else
			{
				if (next_index != head->index + 1)
					return (0);
			}
		}
		head = head->next;
	}
	return (1);
}

int	find_if_backward(t_push **stack)
{
	t_push	*head;
	long	size;
	long	next_index;

	head = *stack;
	size = stack_size(*stack);
	while (head)
	{
		if (head->next != NULL)
		{
			next_index = head->next->index;
			if (head->index == 1)
			{
				if (next_index != size)
					return (0);
			}
			else
			{
				if (next_index != head->index - 1)
					return (0);
			}
		}
		head = head->next;
	}
	return (1);
}

long	count_rotation(t_push **stack, long value)
{
	t_push	*head;
	long	count;
	long	real_count;
	long	min_max[2];

	head = *stack;
	count = 0;
	real_count = 0;
	min_max[0] = find_min(stack, 0);
	min_max[1] = find_max(stack, 0);
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

long	check_max_min_int(long nb, int signe)
{
	if (signe < 0 && nb > 2147483648)
		return (-1);
	else if (signe > 0 && nb > 2147483647)
		return (-1);
	else
		return (0);
}
