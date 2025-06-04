/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:36:48 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 18:00:14 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

void	push_swap(t_list **a)
{
	t_list	*b;
	int		len;

	b = NULL;
	if (stack_trie(*a))
		return ;
	len = stack_len(*a);
	if (len == 2)
		sa(a, 0);
	else if (len == 3)
		tri_trois(a);
	else
		trier_stack(a, &b);
}

// void	print_stack(t_list *a)
// {
// 	while (a)
// 	{
// 		printf("%d\n", a->value);
// 		a = a->next;
// 	}
// }

int	parse_arguments(int argc, char **argv, t_list **a)
{
	char	**split_argv;

	if (argc == 1)
		return (1);
	if (argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		split_argv = split(argv[1], ' ');
		if (!split_argv)
			return (1);
		if (init_stack_a(a, split_argv))
		{
			free_split(split_argv);
			return (1);
		}
		free_split(split_argv);
	}
	else if (init_stack_a(a, argv + 1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	if (parse_arguments(argc, argv, &a))
		return (1);
	push_swap(&a);
	free_stack(&a);
	return (0);
}
