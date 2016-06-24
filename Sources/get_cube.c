/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:09:52 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 19:17:40 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_fill_rot_cube(t_rtv1 *rtv1, char **tri, int i)
{
	rtv1->obj.cube[i].rot.x = (float)ft_atoid(tri[0]);
	rtv1->obj.cube[i].rot.y = (float)ft_atoid(tri[1]);
	rtv1->obj.cube[i].rot.z = (float)ft_atoid(tri[2]);
}

static void		ft_fill_cube(t_rtv1 *rtv1, char ** tab, char **tri, int i)
{
	rtv1->obj.cube[i].posx = ft_atoid(tri[0]);
	rtv1->obj.cube[i].posy = ft_atoid(tri[1]);
	rtv1->obj.cube[i].posz = ft_atoid(tri[2]);
	rtv1->obj.cube[i].size = ft_abs(ft_atoid(tab[1]));
	rtv1->obj.cube[i].color = ft_atoi_base(tab[3], 16);
}

int				ft_get_cube(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		i;
	char	**tab;
	char	**tri;

	tab = NULL;
	tri = NULL;
	if ((i = -1) && (rtv1->nb_cube = ft_atoi(&(*list)->line[11])) == 0)
		return (1);
	rtv1->obj.cube = (t_cube *)ft_memalloc(sizeof(t_cube) * rtv1->nb_cube);
	while (++i < rtv1->nb_cube)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && ((tab = ft_strsplitstr((*list)->line, " / "))
					== NULL || (tri = ft_get_3d_val(tab[0])) == NULL))
			return (1);
		ft_fill_cube(rtv1, tab, tri, i);
		ft_memdel2((void ***)&tri);
		if ((tri = ft_get_3d_val(tab[4])) == NULL)
			return (1);
		ft_fill_rot_cube(rtv1, tri, i);
		ft_memdel2((void ***)&tab);
		ft_memdel2((void ***)&tri);
	}
	return (0);
}
