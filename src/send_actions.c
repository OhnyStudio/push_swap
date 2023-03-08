/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:48:45 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/07 19:37:16 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_actions_print(char *actions, t_push **a, t_push **b, int count)
{
	while (count--)
		send_action(actions, a, b, 1);
}

void	send_actions_no_print(char *actions, t_push **a, t_push **b, int count)
{
	while (count--)
		send_action(actions, a, b, 1);
}
