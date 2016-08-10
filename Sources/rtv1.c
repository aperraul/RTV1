/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:55:28 by aperraul          #+#    #+#             */
/*   Updated: 2016/08/10 14:22:11 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	ft_rtv1(t_rtv1 *rtv1)
{
	int		x;
	int		y;
	t_3dptd	campos;
	t_3dptd	b;

	campos = ft_make_3dptd(0, 0, 0);
	y = -1;
	while (++y < rtv1->env->height)
	{
		x = -1;
		while (++x < rtv1->env->withd)
		{
			b = ft_make_3dptd(x - (rtv1->env->withd / 2), y - (rtv1->env->height), -(rtv1->env->withd / -1.171198));

		}
	}
}

