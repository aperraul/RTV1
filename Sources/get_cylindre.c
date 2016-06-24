/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 12:29:20 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 19:18:18 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_fill_rot_cylindre(t_rtv1 *rtv1, char **tri, int i)
{
	rtv1->obj.cylindre[i].rot.x = (float)ft_atoid(tri[0]);
	rtv1->obj.cylindre[i].rot.y = (float)ft_atoid(tri[1]);
	rtv1->obj.cylindre[i].rot.z = (float)ft_atoid(tri[2]);
}

static void		ft_fill_cylindre(t_rtv1 *rtv1, char **tab, char **tri, int i)
{
	char	*hexa;

	rtv1->obj.cylindre[i].posx = ft_atoid(tri[0]);
	rtv1->obj.cylindre[i].posy = ft_atoid(tri[1]);
	rtv1->obj.cylindre[i].posz = ft_atoid(tri[2]);
	rtv1->obj.cylindre[i].base_size = ft_absd(ft_atoid(tab[1]));
	rtv1->obj.cylindre[i].height = ft_absd(ft_atoid(tab[2]));
	if ((hexa = ft_strstr(tab[3], "0x")))
		rtv1->obj.cylindre[i].color = ft_abs(ft_atoi_base(&hexa[2], 16));
	else
		rtv1->obj.cylindre[i].color = ft_abs(ft_atoi_base(tab[3], 16));
}

int				ft_get_cylindre(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		i;
	char	**tab;
	char	**tri;

	tab = NULL;
	tri = NULL;
	if ((i = -1) && (rtv1->obj.cylindre != NULL || (rtv1->nb_cyl = ft_atoi(&(*list)->line[13])) == 0))
		return (1);
	rtv1->obj.cylindre = (t_cylindre *)ft_memalloc(sizeof(t_cylindre) * rtv1->nb_cyl);
	while (++i < rtv1->nb_cyl)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && ((tab = ft_strsplitstr((*list)->line, " / "))
		== NULL || ft_memlen((void **)tab) != 5 || (tri = ft_get_3d_val(tab[0])) == NULL ||
		!ft_isdouble(tab[1]) || !ft_isdouble(tab[2]) || !ft_strishexa(tab[3])))
			return (1);
		ft_fill_cylindre(rtv1, tab, tri, i);
		ft_memdel2((void ***)&tri);
		if ((tri = ft_get_3d_val(tab[4])) == NULL)
			return (1);
		ft_fill_rot_cylindre(rtv1, tri, i);
		ft_memdel2((void ***)&tab);
		ft_memdel2((void ***)&tri);
	}
	return (0);
}
