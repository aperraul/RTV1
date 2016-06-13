/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:07:38 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/13 15:40:21 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		main(int argc, char **argv)
{
	int		ret;

	if (argc == 2)
	{
		ret = open(argv[1], O_RDONLY);
		
	}
	else
		ft_putstr("nb d'arguments != 1\nusage : ./rtv1 scene");
	return (0);
}
