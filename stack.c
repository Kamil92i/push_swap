/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:00:42 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 17:41:40 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	ajouter_noeud(t_list **stack, int n)
{
	t_list	*noeud;
	t_list	*dernier_noeud;

	if (!stack)
		return ;
	noeud = malloc(sizeof(t_list));
	if (!noeud)
		return ;
	noeud->next = NULL;
	noeud->valeur = n;
	noeud->cheapest = 0;
	if (!(*stack))
	{
		*stack = noeud;
		noeud->prev = NULL;
	}
	else
	{
		dernier_noeud = trouver_dernier(*stack);
		dernier_noeud->next = noeud;
		noeud->prev = dernier_noeud;
	}
}

int	init_stack_a(t_list **a, char **argv)
{
	long	n;
	int		value;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			return (free_errors(a));
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_errors(a));
		value = n;
		if (error_duplicate(*a, value))
			return (free_errors(a));
		ajouter_noeud(a, value);
		i++;
	}
	return (0);
}


t_list	*trouver_noeud_optimal(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	preparer_pour_push(t_list **stack, t_list *top_noeud, char stack_name)
{
	while (*stack != top_noeud)
	{
		if (stack_name == 'a')
		{
			if (top_noeud->mediane)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top_noeud->mediane)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}
