/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:00:28 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 18:04:04 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_trois(t_list **a)
{
	t_list	*biggest_node;

	biggest_node = trouver_max(*a);
	if (biggest_node == *a)
		ra(a, 0);
	else if ((*a)->next == biggest_node)
		rra(a, 0);
	if ((*a)->valeur > (*a)->next->valeur)
		sa(a, 0);
}

static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_noeud;

	cheapest_noeud = trouver_noeud_optimal(*a);
	if (cheapest_noeud->mediane && cheapest_noeud->noeud->mediane)
		rotate_both(a, b, cheapest_noeud);
	else if (!(cheapest_noeud->mediane)
		&& !(cheapest_noeud->noeud->mediane))
		rev_rotate_both(a, b, cheapest_noeud);
	preparer_pour_push(a, cheapest_noeud, 'a');
	preparer_pour_push(b, cheapest_noeud->noeud, 'b');
	pb(b, a, 0);
}

static void	move_b_to_a(t_list **a, t_list **b)
{
	preparer_pour_push(a, (*b)->noeud, 'a');
	pa(a, b, 0);
}

static void	min_on_top(t_list **a)
{
	while ((*a)->valeur != trouver_min(*a)->valeur)
	{
		if (trouver_min(*a)->mediane)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	trier_stack(t_list **a, t_list **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_trie(*a))
		pb(b, a, 0);
	if (len_a-- > 3 && !stack_trie(*a))
		pb(b, a, 0);
	while (len_a-- > 3 && !stack_trie(*a))
	{
		init_noeud_a(*a, *b);
		move_a_to_b(a, b);
	}
	tri_trois(a);
	while (*b)
	{
		init_noeud_b(*a, *b);
		move_b_to_a(a, b);
	}
	indexer_pile(*a);
	min_on_top(a);
}
