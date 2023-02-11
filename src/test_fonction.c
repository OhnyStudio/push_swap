/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:05:07 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/11 11:22:25 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	split_median(t_push **stack_a, t_push **stack_b)
// {
// 	t_push	*head;
// 	t_push	*tmp;
// 	int		median;
// 	int		size;

// 	median = find_median(stack_a);
// 	head = *stack_a;
// 	size = stack_size(*stack_a);
// 	while (size--)
// 	{
// 		if (head->value < median)
// 		{
// 			tmp = head->next;
// 			send_action("pb", stack_a, stack_b, 1);
// 			head = tmp;
// 		}
// 		else
// 		{
// 			send_action("ra", stack_a, stack_b, 1);
// 			head = *stack_a;
// 		}
// 	}
// }

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
