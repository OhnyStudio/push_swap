/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:21:38 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/08 16:28:00 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_push **stack)
{
	t_push	*head;
	t_push	*tail;
	t_push	*tmp;

	head = *stack;
	tmp = head;
	while (tmp)
	{
		if (tmp->next == NULL)
			tail = tmp;
		tmp = tmp->next;
	}
	
}

int	ra(t_push **stack_a)
{
	//ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
	//Le premier élément devient le dernier.
}

int	rb(t_push **stack_b)
{
	//rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
	//Le premier élément devient le dernier.
}

int	rb(t_push **stack_a, t_push **stack_b)
{
	//rr : ra et rb en même temps.
}
