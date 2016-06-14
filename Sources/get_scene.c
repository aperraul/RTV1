/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:49:25 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/14 15:10:38 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	ft_get_scene(t_rtv1 *rtv1, int ret)
{
	char	*line;
	int		t;

	line = NULL;
	while ((t = get_next_line(ret, &line)) == 1)
	{
		//do parthing;
	}
	if (t == -1)
	{
		ft_putstr("bad file");
		ft_del_rtv1(rtv1);
		exit(0);
	}
}
