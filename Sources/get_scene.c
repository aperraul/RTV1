/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:49:25 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/17 14:17:58 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"
#include <stdio.h>

int		ft_check_3d_value(char *tab)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	if (tab[i] == '-')
		i++;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]) == 1)
			i++;
		else if (tab[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}

char		**ft_get_3d_val(char *line)
{
	int		i;
	char	**tab;

	i = -1;
	tab = NULL;
	while (line[++i] == '\t')
		;
	tab = ft_strsplit(&line[i], ' ');
	if (ft_memlen((void **)(tab)) != 3)
	{
		ft_memdel2((void ***)&tab);
		return (tab);
	}
	if (ft_check_3d_value(tab[0]) != 0 || ft_check_3d_value(tab[1]) != 0 ||
			ft_check_3d_value(tab[2]) != 0)
	{
		ft_memdel2((void ***)&tab);
		return (tab);
	}
	return (tab);
}

int		ft_get_cam(t_lstline *list, t_rtv1 *rtv1, int *line_nb)
{
	char	**str1;
	char	**str2;

	str1 = NULL;
	str2 = NULL;
	if ((*line_nb += 1) && list->line &&
			(ft_strcmp(list->line, "\t###Cam") == 0))
		list = list->next;
	else
		return (ft_syntaxe_error(*line_nb));
	if ((*line_nb += 1) && (str1 = ft_get_3d_val(list->line)) == NULL)
		return (ft_syntaxe_error(*line_nb));
	list = list->next;
	if ((*line_nb += 1) && (str2 = ft_get_3d_val(list->line)) == NULL)
		return (ft_syntaxe_error(*line_nb));
	rtv1->cam.posx = ft_atoid(str1[0]);
	rtv1->cam.posy = ft_atoid(str1[1]);
	rtv1->cam.posz = ft_atoid(str1[2]);
	rtv1->cam.dir.x = ft_atoid(str2[0]);
	rtv1->cam.dir.y = ft_atoid(str2[1]);
	rtv1->cam.dir.z = ft_atoid(str2[2]);
	ft_memdel2((void ***)&str1);
	ft_memdel2((void ***)&str2);
	return (0);
}

int		ft_scene(t_lstline *list, t_rtv1 *rtv1, int *line_nb)
{
	if (list->line && (ft_strcmp(list->line, "#Scene#") == 0))
		list = list->next;
	else
		return (ft_syntaxe_error(*line_nb));
	if (ft_get_cam(list, rtv1, line_nb) != 0)
		return (1);

	return (0);
}

void	ft_get_scene(t_rtv1 *rtv1, int ret)
{
	char		*line;
	t_lstline	*list;
	int			t;
	int			line_nb;

	line = NULL;
	list = NULL;
	line_nb = 0;
	while ((t = get_next_line(ret, &line)) == 1)
		list = ft_add_list(list, line);
	if (t == -1)
	{
		ft_putstr("bad file");
		ft_del_rtv1(rtv1);
		exit(0);
	}
	if (ft_scene(list, rtv1, &line_nb) > 0)
	{
		ft_putendl("file syntaxe error");
		ft_lstline_del(list);
		ft_del_rtv1(rtv1);
		exit(0);
	}
}
