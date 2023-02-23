/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:21:55 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/23 16:44:46 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotation(t_push **stack)
{
	t_push	*head;

	head = *stack;
	while (head)
	{
		if (head->current_index > head->index)
		{
			head->nb_r = head->current_index - head->index;
			head->nb_rr = stack_size(*stack) - head->nb_r;
		}
		else if (head->current_index < head->index)
		{
			head->nb_rr = head->index - head->current_index;
			head->nb_r = stack_size(*stack) - head->nb_rr;
		}
		else
		{
			head->nb_r = 0;
			head->nb_rr = 0;
		}
		if (head->next != NULL)
		{
			if (head->current_index == head->next->index
				&& head->next->current_index == head->index)
			{
				head->need_swap = 1;
				head->next->need_swap = 1;
			}
		}
		head = head->next;
	}
}

char	*check_if_r_or_rr(t_push **stack)
{
	int		count_r;
	int		count_rr;
	t_push	*head;

	head = *stack;
	count_r = 0;
	count_rr = 0;
	while (head)
	{
		if (head->nb_r > head->nb_rr)
			count_r++;
		else
			count_rr++;
		head = head->next;
	}
	if (count_r > count_rr)
		return ("r");
	else
		return ("rr");
}
