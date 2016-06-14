/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:15:26 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/26 19:31:12 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	cpt;

	if (s)
	{
		cpt = 0;
		while (s[cpt])
		{
			s[cpt] = '\0';
			cpt++;
		}
	}
}
