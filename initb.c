/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:01:14 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 17:56:37 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	definir_cible_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*noeud;
	long	best_m_i;

	while (b)
	{
		best_m_i = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->valeur > b->valeur && current_a->valeur < best_m_i)
			{
				best_m_i = current_a->valeur;
				noeud = current_a;
			}
			current_a = current_a->next;
		}
		if (best_m_i == LONG_MAX)
			b->noeud = trouver_min(a);
		else
			b->noeud = noeud;
		b = b->next;
	}
}

void	init_noeud_b(t_list *a, t_list *b)
{
	indexer_pile(a);
	indexer_pile(b);
	definir_cible_b(a, b);
}
