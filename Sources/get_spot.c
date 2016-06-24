/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 10:44:16 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 19:20:33 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_get_spot(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		i;
	char	**tab;
	char	**tri;

	tab = NULL;
	tri = NULL;
	if ((i = -1) && (rtv1->obj.spot != NULL || (rtv1->nb_spot = ft_atoi(&(*list)->line[9])) == 0))
		return (1);
	rtv1->obj.spot = (t_spot *)ft_memalloc(sizeof(t_spot) * rtv1->nb_spot);
	while (++i < rtv1->nb_spot)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && ((tab = ft_strsplitstr((*list)->line, " / "))
		== NULL || ft_memlen((void **)tab) != 2 || (tri = ft_get_3d_val(tab[0])) == NULL || !ft_isdouble(tab[1])))
			return (1);
		if (!ft_isdouble(tab[1]))
			return (1);
		rtv1->obj.spot[i].posx = ft_atoid(tri[0]);
		rtv1->obj.spot[i].posy = ft_atoid(tri[1]);
		rtv1->obj.spot[i].posz = ft_atoid(tri[2]);
		rtv1->obj.spot[i].lux = ft_absd(ft_atoid(tab[1]));
		ft_memdel2((void ***)&tab);
		ft_memdel2((void ***)&tri);
	}
	return (0);
}
