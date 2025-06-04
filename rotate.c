/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:02:11 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 17:50:59 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*dernier_noeud;

	if (!*stack || !(*stack)->next)
		return ;
	dernier_noeud = trouver_dernier(*stack);
	dernier_noeud->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	dernier_noeud->next->prev = dernier_noeud;
	dernier_noeud->next->next = NULL;
}

void	ra(t_list **a, int print)
{
	rotate(a);
	if (!print)
		ft_putstr("ra\n");
}

void	rb(t_list **b, int print)
{
	rotate(b);
	if (!print)
		ft_putstr("rb\n");
}

void	rr(t_list **a, t_list **b, int print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_putstr("rr\n");
}
