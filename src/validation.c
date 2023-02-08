/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:20 by johnysavard       #+#    #+#             */
/*   Updated: 2023/02/07 20:57:06 by johnysavard      ###   ########.fr       */
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

	temp = *stack;
	current = temp->value;
	while (temp)
	{
		if (temp->next != NULL)
		{
			if (current > temp->next->value)
				return (0);
			current = temp->value;
		}
		temp = temp->next;
	}
	if (temp)
		free(temp);
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
