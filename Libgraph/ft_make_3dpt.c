/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_3Dpt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:02 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/13 15:51:21 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_3dpt		ft_make_3dpt(int x, int y, int z)
{
	t_3dpt		pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

t_3dptd		ft_make_3dptd(double x, double y, double z)
{
	t_3dptd		pos;

	pos.x = x;
	pox.y = y;
	pos.z = z;
	return (pos);
}
