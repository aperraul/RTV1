/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 14:57:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/24 17:22:00 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strishexa(char *str)
{
	char	*hexa;
	int		i;
	int		end;

	i = -1;
	end = 0;
	while (str[++i] == ' ')
		;
	if (i == '-')
		i++;
	hexa = ft_strstr(str, "0x");
	if (hexa)
	{
		if (&str[i] != hexa)
			return (0);
		i += 2;
	}
	while (str[i])
	{
		if (ft_ishexa(str[i]) && !end)
			;
		else if (str[i] == ' ')
			end = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
