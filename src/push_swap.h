/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:52 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/08 23:14:56 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_push
{
	int				value;
	int				index;
	struct s_push	*next;
}	t_push;

//Validation
int		is_int(char **argv);
int		check_twin(char	**argv);
int		is_sorted(t_push **stack);
int		stack_size(t_push *stack);
//Utils
void	add_back_stack(t_push **stack, t_push *new);
void	add_front_stack(t_push **stack, t_push *new);
void	sort_stack(t_push **stack_a, t_push **stack_b);
t_push	*create_new_node(int value);
//Action Swap
int		sa(t_push **stack_a);
int		sb(t_push **stack_b);
int		ss(t_push **stack_a, t_push **stack_b);
//Action Push
int		pa(t_push **stack_a, t_push **stack_b);
int		pb(t_push **stack_b, t_push **stack_a);
//Action Rotate
void	ra(t_push **stack_a);
void	rb(t_push **stack_b);
void	rr(t_push **stack_a, t_push **stack_b);
//Action RRotate
void	rra(t_push **stack_a);
void	rrb(t_push **stack_b);
void	rrr(t_push **stack_a, t_push **stack_b);
//Find
int		find_min(t_push	**stack);
int		find_max(t_push	**stack);
//Algo
void	algo2(t_push **stack);
void	algo3(t_push **stack_a, int min, int max);
void	algo4(t_push **stack_a, t_push **stack_b, int min, int max);
//Algo Utils
void	min_to_top(t_push **stack, int min);
#endif