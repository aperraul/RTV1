/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:49:25 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/15 17:36:51 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_check_pos_value(char *tab)
{
	int		j;
	int		dot;
	int		error;

	j = -1;
	error = 0;
	dot = 0;
	while (tab[++j])
	{
		if (j == 0)
		{
			if (tab[j] != '+' && tab[j] != '-' && ft_isdigit(tab[j]) == 0)
				error++;
			if ((tab[j] == '+' || tab[j] == '-') && ft_isdigit(tab[j + 1]) == 0)
				error++;
		}
		else
		{
			if (tab[j] != '.' && ft_isdigit(tab[j]) == 0)
				error++;
			if (tab[j] == '.')
			{
				dot++;
				if (dot > 1 || ft_isdigit(tab[j + 1]) == 0)
					error++;
			}
		}
	}
	return (error);
}

int		ft_cam_lines(char **tab, char *line)
{
	int		i;

	i = -1;
	while (++i < 3)
		if (line[i] != '\t')
			return (1);
	tab = ft_strsplit(&line[i], ' ');
	i = -1;
	while (tab[++i])
	{
		if (ft_check_pos_value(tab[i]) != 0)
		{
//			ft_del_tab;
			return (1);
		}
	}
	if (i != 2)
	{
//		ft_del_tab;
		return (1);
	}
	return (0);
}

#include <stdio.h>

int		ft_get_cam(t_lstline *list, t_rtv1 *rtv1)
{
	char	**str1;
	char	**str2;

	str1 = NULL;
	str2 = NULL;
	if (list->line && (ft_strcmp(list->line, "\t###cam") == 0))
		list = list->next;
	else
	{
		ft_putstr("scene syntaxe error line 2");
		return (1);
	}
	if (ft_cam_lines(&*str1, list->line) > 0)
		return (1);
	list = list->next;
	if (ft_cam_lines(&*str2, list->line) > 0)
		return (1);
	rtv1->cam.posx = ft_atoid(str1[1]);
	printf("%f\n", rtv1->cam.posx);
	sleep(100000);
	return (0);
}

int		ft_scene(t_lstline *list, t_rtv1 *rtv1)
{
	ft_putstr(list->line);
	if (list->line && (ft_strcmp(list->line, "#Scene#") == 0))
		list = list->next;
	else
	{
		ft_putstr("scene syntaxe error line 1");
		return(1);
	}
	if (ft_get_cam(list, rtv1) != 0)
		return (1);

	return (0);
}

void	ft_get_scene(t_rtv1 *rtv1, int ret)
{
	char		*line;
	t_lstline	*list;
	int			t;

	line = NULL;
	while ((t = get_next_line(ret, &line)) == 1)
		list = ft_add_list(list, line);
	if (t == -1)
	{
		ft_putstr("bad file");
		ft_del_rtv1(rtv1);
		exit(0);
	}
	if (ft_scene(list, rtv1) > 0)
	{
		ft_lstline_del(list);
		ft_del_rtv1(rtv1);
		exit(0);
	}
}
