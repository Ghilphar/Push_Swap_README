/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pushs_sa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:54:39 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 00:09:38 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	operate_sa(t_start *start)
{
	rotate_a(start);
	write(1, "sa\n", 3);
}

void	operate_pa(t_start *start, int i)
{
	while (i-- > 0)
	{
		push_a(start);
		write(1, "pa\n", 3);
	}
}

void	operate_pb(t_start *start, int i)
{
	while (i-- > 0)
	{
		push_b(start);
		write(1, "pb\n", 3);
	}
}

void	final_push_a(t_start *start)
{
	operate_pa(start, start->data->nb_list_b);
}
