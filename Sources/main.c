/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:07:38 by aperraul          #+#    #+#             */
/*   Updated: 2016/08/10 12:52:27 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		main(int argc, char **argv)
{
	int			ret;
	t_rtv1		*rtv1;

	rtv1 = NULL;
	if (argc == 2)
	{
	if ((ret = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("file error");
		return (0);
	}
		rtv1 = ft_rtv1_init();
		ft_get_scene(rtv1, ret);
		printf("\nsphere :\n%f %f %f, %f, %d\n", rtv1->obj.sphere[0].posx, rtv1->obj.sphere[0].posy, rtv1->obj.sphere[0].posz,
			rtv1->obj.sphere[0].r, rtv1->obj.sphere[0].color);
		printf("%f %f %f, %f, %d\n", rtv1->obj.sphere[1].posx, rtv1->obj.sphere[1].posy, rtv1->obj.sphere[1].posz,
			rtv1->obj.sphere[1].r, rtv1->obj.sphere[1].color);
		printf("%f %f %f, %f, %d\n", rtv1->obj.sphere[2].posx, rtv1->obj.sphere[2].posy, rtv1->obj.sphere[2].posz,
			rtv1->obj.sphere[2].r, rtv1->obj.sphere[2].color);
		printf("\nspot : \n%f %f %f, %f\n", rtv1->obj.spot[0].posx, rtv1->obj.spot[0].posy, rtv1->obj.spot[0].posz, rtv1->obj.spot[0].lux);
		printf("%f %f %f, %f\n", rtv1->obj.spot[1].posx, rtv1->obj.spot[1].posy, rtv1->obj.spot[1].posz, rtv1->obj.spot[1].lux);
		printf("\ncylindre :\n%f %f %f, %f, %f, %d, %f %f %f\n", rtv1->obj.cylindre[0].posx, rtv1->obj.cylindre[0].posy,
				rtv1->obj.cylindre[0].posz, rtv1->obj.cylindre[0].base_size, rtv1->obj.cylindre[0].height, rtv1->obj.cylindre[0].color,
				rtv1->obj.cylindre[0].rot.x, rtv1->obj.cylindre[0].rot.y, rtv1->obj.cylindre[0].rot.z);
		printf("%f %f %f, %f, %f, %d, %f %f %f\n", rtv1->obj.cylindre[1].posx, rtv1->obj.cylindre[1].posy,
				rtv1->obj.cylindre[1].posz, rtv1->obj.cylindre[1].base_size, rtv1->obj.cylindre[1].height, rtv1->obj.cylindre[1].color,
				rtv1->obj.cylindre[1].rot.x, rtv1->obj.cylindre[1].rot.y, rtv1->obj.cylindre[1].rot.z);
		printf("\ncone :\n%f %f %f, %f, %f, %d, %f %f %f\n", rtv1->obj.cone[0].posx, rtv1->obj.cone[0].posy, rtv1->obj.cone[0].posz,
				rtv1->obj.cone[0].base_size, rtv1->obj.cone[0].height, rtv1->obj.cone[0].color, rtv1->obj.cone[0].rot.x,
				rtv1->obj.cone[0].rot.y, rtv1->obj.cone[0].rot.z);
		printf("%f %f %f, %f, %f, %d, %f %f %f\n", rtv1->obj.cone[1].posx, rtv1->obj.cone[1].posy, rtv1->obj.cone[1].posz,
				rtv1->obj.cone[1].base_size, rtv1->obj.cone[1].height, rtv1->obj.cone[1].color, rtv1->obj.cone[1].rot.x,
				rtv1->obj.cone[1].rot.y, rtv1->obj.cone[1].rot.z);
		printf("\nplan :\n%f %f %f, %f, %f, %d, %f %f %f\n", rtv1->obj.plan[0].posx, rtv1->obj.plan[0].posy, rtv1->obj.plan[0].posz,
				rtv1->obj.plan[0].withd, rtv1->obj.plan[0].height, rtv1->obj.plan[0].color,
				rtv1->obj.plan[0].rot.x, rtv1->obj.plan[0].rot.y, rtv1->obj.plan[0].rot.z);
		printf("%f %f %f, %f, %f, %d, %f %f %f\n", rtv1->obj.plan[1].posx, rtv1->obj.plan[1].posy, rtv1->obj.plan[1].posz,
				rtv1->obj.plan[1].withd, rtv1->obj.plan[1].height, rtv1->obj.plan[1].color,
				rtv1->obj.plan[1].rot.x, rtv1->obj.plan[1].rot.y, rtv1->obj.plan[1].rot.z);

	ft_rtv1(rtv1);




	}
	else
		ft_putstr("nb d'arguments != 1\nusage : ./rtv1 scene");
	return (0);
}
