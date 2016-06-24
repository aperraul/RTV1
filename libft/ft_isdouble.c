/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:33:09 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 13:45:06 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isdouble_loop(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int				ft_isdouble(char *str)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	while (ft_isescseq(str[i]))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '.' || str[i] == ' ')
			i++;
		if (str[i] == '.')
		{
			dot++;
			i++;
			if (dot > 1)
				return (0);
		}
		if (str[i] == ' ')
			if (ft_isdouble_loop(&str[i]) == 0)
				return (0);
	}
	return (1);
}
