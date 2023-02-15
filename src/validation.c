/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:20 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/15 15:03:54 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_push **stack)
{
	t_push	*temp;
	int		current;
	int		is_ok;

	temp = *stack;
	current = temp->value;
	is_ok = 1;
	while (temp)
	{
		if (temp->next != NULL)
		{
			if (current > temp->next->value)
			{
				is_ok = 0;
				break ;
			}
		}
		temp = temp->next;
		if (temp != NULL)
			current = temp->value;
	}
	return (is_ok);
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
