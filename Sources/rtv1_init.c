/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:37:34 by aperraul          #+#    #+#             */
/*   Updated: 2016/08/10 12:19:30 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void		ft_del_rtv1(t_rtv1 *rtv1)
{
	if (rtv1)
		free(rtv1);
}

t_rtv1		*ft_rtv1_init(void)
{
	t_rtv1		*rtv1;

	rtv1 = (t_rtv1 *)ft_memalloc(sizeof(t_rtv1));
	rtv1->env = NULL;
	rtv1->env = ft_sdl_init(500, 500, "RTV1");
	rtv1->obj.spot = NULL;
	rtv1->obj.sphere = NULL;
	rtv1->obj.cylindre = NULL;
	rtv1->obj.plan = NULL;
	rtv1->obj.cone = NULL;
	rtv1->obj.cube = NULL;
	return (rtv1);
}
