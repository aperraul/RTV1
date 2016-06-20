/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 12:20:23 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/20 12:33:53 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_get_sphere(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		i;
	char	**tab;
	char	**tri;

	tab = NULL;
	tri = NULL;
	if ((i = -1) && (rtv1->nb_sph = ft_atoi(&(*list)->line[11])) == 0)
		return (1);
	rtv1->obj.sphere = (t_sphere *)ft_memalloc(sizeof(t_sphere) * rtv1->nb_sph);
	while (++i < rtv1->nb_sph)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && ((tab = ft_strsplitstr((*list)->line, " / "))
					== NULL || (tri = ft_get_3d_val(tab[0])) == NULL))
			return (1);
		rtv1->obj.sphere[i].posx = ft_atoid(tri[0]);
		rtv1->obj.sphere[i].posy = ft_atoid(tri[1]);
		rtv1->obj.sphere[i].posz = ft_atoid(tri[2]);
		rtv1->obj.sphere[i].r = ft_atoid(tab[1]);
//		rtv1->obj.sphere[i].color = ft_atoi(tab[2]);
		ft_memdel2((void ***)&tab);
		ft_memdel2((void ***)&tri);
	}
	return (0);
}
