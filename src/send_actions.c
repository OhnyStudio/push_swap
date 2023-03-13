/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:48:45 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/13 11:38:14 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_actions(char *actions, t_push **a, t_push **b, int count)
{
	while (count--)
		send_action(actions, a, b, 1);
}
