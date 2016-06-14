/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:07:38 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/14 14:51:08 by aperraul         ###   ########.fr       */
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
		ft_get_scene(rtv1);
	}
	else
		ft_putstr("nb d'arguments != 1\nusage : ./rtv1 scene");
	return (0);
}
