/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:53:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 14:52:00 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_start		*start;

	if (!(start = malloc(sizeof(t_start))))
		return (0);
	start->list_a = NULL;
	start->list_b = NULL;
	if (!(start->data = malloc(sizeof(t_data))))
		return (0);
	ft_initialise(ac, av, &start);
	check_empty(start);
	ft_double(&start);
	if (test_sorted(start) == 1)
	{
		clear_leaks_2(start);
		return (0);
	}
	ft_algo(start);
	clear_leaks(start);
	return (0);
}
