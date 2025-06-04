/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:01:06 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 17:48:47 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **a, t_list **b, t_list *cheapest_noeud)
{
	while (*b != cheapest_noeud->noeud && *a != cheapest_noeud)
		rr(a, b, 0);
	indexer_pile(*a);
	indexer_pile(*b);
}

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_noeud)
{
	while (*b != cheapest_noeud->noeud && *a != cheapest_noeud)
		rrr(a, b, 0);
	indexer_pile(*a);
	indexer_pile(*b);
}
