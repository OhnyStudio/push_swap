/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:06:58 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/06 11:09:26 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_actions(char *action, t_push **a, t_push **b, int count)
{
	int	i;

	i = count;
	while (count--)
		send_action(action, a, b, 1);
}
