/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:34:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 19:41:56 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*ft_new(int nb)
{
	t_stack		*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_add(t_start **start, char *num)
{
	t_stack *new;
	t_stack *tmp;

	new = ft_new(ft_atoi(num));
	tmp = (*start)->list_a;
	if (tmp == NULL)
		(*start)->list_a = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_initialise(int ac, char **av, t_start **start)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	while (++i < ac)
	{
		tab = NULL;
		j = 0;
		tab = ft_strsplit(av[i], ' ');
		while (tab[j] != NULL)
		{
			if (ft_isanint(tab[j]) == 1)
				ft_add(start, tab[j]);
			else
			{
				free_tab(tab);
				ft_exit_error(*start);
			}
			j++;
		}
		free_tab(tab);
	}
}

void	check_empty(t_start *start)
{
	if (start->list_a == 0)
	{
		free(start->data);
		free(start);
		exit(EXIT_SUCCESS);
	}
}

void	ft_operate(t_start *start)
{
	char	**l;
	int		ret;

	l = malloc(sizeof(l));
	while ((ret = get_next_line(0, l)) == 1)
	{
		if ((ft_strcmp(*l, "sa\n")) == 0 || (ft_strcmp(*l, "sb\n") == 0)
		|| (ft_strcmp(*l, "ss\n") == 0))
			ft_swaps(*l, start);
		else if ((ft_strcmp(*l, "pa\n") == 0) || (ft_strcmp(*l, "pb\n") == 0))
			ft_pushs(*l, start);
		else if ((ft_strcmp(*l, "ra\n") == 0) ||
		(ft_strcmp(*l, "rb\n") == 0) || (ft_strcmp(*l, "rr\n") == 0))
			ft_rotates(*l, start);
		else if ((ft_strcmp(*l, "rra\n") == 0) ||
		(ft_strcmp(*l, "rrb\n") == 0)
		|| (ft_strcmp(*l, "rrr\n") == 0))
			ft_reverse_rotates(*l, start);
		else
			exit_gnl(start, l);
		free(*l);
	}
	free(*l);
	free(l);
}
