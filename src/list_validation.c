/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:20 by johnysavard       #+#    #+#             */
/*   Updated: 2023/03/07 13:13:18 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_int(char **argv)
{
	int	i;
	int	j;

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

int	check_twin(char	**argv)
{
	int	i;
	int	j;

	i = 1;
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
	int		is_ok;

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
	int		is_ok;

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

int	stack_size(t_push *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
