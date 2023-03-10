/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:20 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/14 09:28:00 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_int(char **argv)
{
	long	i;
	long	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) != 1 && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_twin(char	**argv, long i)
{
	long	j;

	while (argv[i])
	{
		j = 1 + i;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_push **stack)
{
	t_push	*head;
	long	is_ok;

	head = *stack;
	is_ok = 1;
	while (head)
	{
		if (head->next != NULL)
		{
			if (head->value > head->next->value)
			{
				is_ok = 0;
				break ;
			}
		}
		head = head->next;
	}
	return (is_ok);
}

int	is_reverse_sorted(t_push **stack)
{
	t_push	*head;
	long	is_ok;

	head = *stack;
	is_ok = 1;
	while (head)
	{
		if (head->next != NULL)
		{
			if (head->value < head->next->value)
			{
				is_ok = 0;
				break ;
			}
		}
		head = head->next;
	}
	return (is_ok);
}

long	stack_size(t_push *stack)
{
	long	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
