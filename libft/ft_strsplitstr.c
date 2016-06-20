/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:41:58 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/19 16:25:11 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbstr(char *str, const char *split, int size)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (strncmp(&str[i], split, size) == 0)
			i += size;
		if (str[i] && (strncmp(&str[i], split, size) != 0))
			nb++;
		while (str[i] && (strncmp(&str[i], split, size) != 0))
			i++;
	}
	return (nb);
}

static int	ft_size(char *str, const char *split, int size)
{
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (str[++i] && (ft_strncmp(&str[i], split, size) != 0))
		len++;
	if (len == 0)
		len = 1;
	return (len);
}

char		**ft_strsplitstr(char *str, const char *split)
{
	char	**tab;
	char	*s;
	t_pt	k;
	int		size;

	tab = NULL;
	size = ft_strlen(split);
	s = NULL;
	if (!str || !split)
		return (NULL);
	tab = (char **)ft_memalloc(sizeof(char *) * ft_nbstr(str, split, size) + 1);
	k.x = 0;
	k.y = 0;
	while (str[k.y])
	{
		if (ft_strncmp(&str[k.y], split, size) == 0)
			k.y += size;
		else
		{
			tab[k.x] = ft_strsub(str, k.y, ft_size(&str[k.y], split, size));
			if (tab[k.x] == NULL)
				return (NULL);
			k.y += ft_size(&str[k.y], split, size);
			k.x++;
		}
	}
	tab[k.x] = NULL;
	return (tab);
}
