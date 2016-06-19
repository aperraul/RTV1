/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 10:44:16 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/19 12:12:28 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"
#include <stdio.h>

int		ft_get_spot(t_rtv1 *rtv1, t_lstline **list, int *line_nb)
{
	int		k;
	char	*str;
	char	**str1;

	str1 = NULL;
	str = ft_strdup(&(*list)->line[10]);
	if ((k = ft_atoi(str)) == 0)
		return (1);
	ft_memdel((void **)&str);
	rtv1->obj.spot = (t_spot *)ft_memalloc(sizeof(t_spot) * k);
	while (k > 0)
	{
		*list = (*list)->next;
		if ((*line_nb += 1) && (str1 = ft_get_3d_val((*list)->line)) == NULL)
			return (ft_syntaxe_error(*line_nb));
		rtv1->obj.spot[k].posx = ft_atoid(str1[0]);
		rtv1->obj.spot[k].posy = ft_atoid(str1[1]);
		rtv1->obj.spot[k].posz = ft_atoid(str1[2]);
		ft_memdel2((void ***)&str1);
		printf("%f\n", rtv1->obj.spot[k].posx);
		k--;
	}
	sleep(11110001);
	return (0);
}
