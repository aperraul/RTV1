/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:03:33 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 19:17:06 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_fill_rot_cone(t_rtv1 *rtv1, char **tri, int i)
{
	rtv1->obj.cone[i].rot.x = (float)ft_atoid(tri[0]);
	rtv1->obj.cone[i].rot.y = (float)ft_atoid(tri[1]);
	rtv1->obj.cone[i].rot.z = (float)ft_atoid(tri[2]);
}

static void		ft_fill_cone(t_rtv1 *rtv1, char **tab, char **tri, int i)
{
	char	*hexa;

	rtv1->obj.cone[i].posx = ft_atoid(tri[0]);
	rtv1->obj.cone[i].posy = ft_atoid(tri[1]);
	rtv1->obj.cone[i].posz = ft_atoid(tri[2]);
	rtv1->obj.cone[i].base_size = ft_atoid(tab[1]);
	rtv1->obj.cone[i].height = ft_atoid(tab[2]);
	if ((hexa = ft_strstr(tab[3], "0x")))
		rtv1->obj.cone[i].color = ft_abs(ft_atoi_base(&hexa[2], 16));
	else
		rtv1->obj.cone[i].color = ft_abs(ft_atoi_base(tab[3], 16));

}

int				ft_get_cone(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		i;
	char	**tab;
	char	**tri;

	tab = NULL;
	tri = NULL;
	if ((i = -1) && ((rtv1->obj.cone != NULL || (rtv1->nb_cone = ft_atoi(&(*list)->line[9]))) == 0))
		return (1);
	rtv1->obj.cone = (t_cone *)ft_memalloc(sizeof(t_cone) * rtv1->nb_cone);
	while (++i < rtv1->nb_cone)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && ((tab = ft_strsplitstr((*list)->line, " / "))
					== NULL || ft_memlen((void **)tab) != 5 || (tri = ft_get_3d_val(tab[0])) == NULL
				|| !ft_isdouble(tab[1]) || !ft_isdouble(tab[2]) || !ft_strishexa(tab[3])))
			return (1);
		ft_fill_cone(rtv1, tab, tri, i);
		ft_memdel2((void ***)&tri);
		if ((tri = ft_get_3d_val(tab[4])) == NULL)
			return (1);
		ft_fill_rot_cone(rtv1, tri, i);
		ft_memdel2((void ***)&tab);
		ft_memdel2((void ***)&tri);
	}
	return (0);
}
