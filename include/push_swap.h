/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:52 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/14 09:26:19 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_push
{
	long			value;
	long			index;
	struct s_push	*next;
}	t_push;

//Algo Utils
long	ra_or_rra(t_push **stack, long max);
void	min_to_top_4(t_push **stack_a, t_push **stack_b, long min);
void	min_to_top_5(t_push **stack_a, t_push **stack_b, long min);
void	set_backward(t_push **stack_a, t_push **stack_b, long max);
void	make_rotation(t_push **stack_a, t_push **stack_b, long max);
//Algo
void	sort_stack(t_push **stack_a, t_push **stack_b);
//Algo 6
void	algo6(t_push **stack_a, t_push **stack_b, long min, long max);
//Algo Binary
int		find_max_bit(long max);
void	move_bit_a(t_push **stack_a, t_push **stack_b, int bit);
void	move_bit_b(t_push **stack_a, t_push **stack_b, int bit);
//Base action
int		send_action(char *action, t_push **a, t_push **b, int is_print);
//List creator
void	add_back_stack(t_push **stack, t_push *new);
void	add_front_stack(t_push **stack, t_push *new);
void	set_index(t_push **stack, long current_min, long index);
//List split
int		split_nb(t_push **a, t_push **b, int origin_split);
//List validation Other
int		find_if_rotate(t_push **stack);
int		find_if_backward(t_push **stack);
long	check_max_min_int(long nb, int signe);
long	count_rotation(t_push **stack, long value);
void	ft_print_list(t_push **a);
//List validation
int		is_int(char **argv);
int		check_twin(char	**argv, long i);
int		is_sorted(t_push **stack);
int		is_reverse_sorted(t_push **stack);
long	stack_size(t_push *stack);
//List value finder
long	find_min(t_push	**stack, int needindex);
long	find_max(t_push	**stack, int needindex);
long	find_tail(t_push **stack, int needindex);
//Send Actions
void	free_list(t_push **stack);
void	send_actions(char *actions, t_push **a, t_push **b, long count);
#endif