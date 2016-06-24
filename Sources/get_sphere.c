/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 12:20:23 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 19:22:25 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_fill_sphere(t_rtv1 *rtv1, char **tab, char **tri, int i)
{
	char	*hexa;

	rtv1->obj.sphere[i].posx = ft_atoid(tri[0]);
	rtv1->obj.sphere[i].posy = ft_atoid(tri[1]);
	rtv1->obj.sphere[i].posz = ft_atoid(tri[2]);
	rtv1->obj.sphere[i].r = ft_absd(ft_atoid(tab[1]));
	if ((hexa = ft_strstr(tab[2], "0x")))
		rtv1->obj.sphere[i].color = ft_abs(ft_atoi_base(&hexa[2], 16));
	else
		rtv1->obj.sphere[i].color = ft_abs(ft_atoi_base(tab[2], 16));
}

int		ft_get_sphere(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		i;
	char	**tab;
	char	**tri;

	tab = NULL;
	tri = NULL;
	if ((i = -1) && (rtv1->obj.sphere != NULL || (rtv1->nb_sph = ft_atoi(&(*list)->line[11])) == 0))
		return (1);
	rtv1->obj.sphere = (t_sphere *)ft_memalloc(sizeof(t_sphere) * rtv1->nb_sph);
	while (++i < rtv1->nb_sph)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && ((tab = ft_strsplitstr((*list)->line, " / "))
		== NULL || ft_memlen((void **)tab) != 3 || (tri = ft_get_3d_val(tab[0])) == NULL || 
		!ft_isdouble(tab[1]) || !ft_strishexa(tab[2])))
			return (1);
		ft_fill_sphere(rtv1, tab, tri, i);
		ft_memdel2((void ***)&tab);
		ft_memdel2((void ***)&tri);
	}
	return (0);
}
