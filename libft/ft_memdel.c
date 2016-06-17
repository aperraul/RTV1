/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:47:48 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/17 11:16:05 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_memdel2(void ***ap)
{
	int		i;

	if (ap != NULL && *ap != NULL)
	{
		i = -1;
		while ((*ap)[++i])
			ft_memdel((void **)&(*ap)[i]);
		free(*ap);
		*ap = NULL;
	}
}
