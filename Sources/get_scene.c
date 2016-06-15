/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:49:25 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/15 16:04:10 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_check_cam_lines(char *line)
{
	int i;

	if (line)
	{
		i = 0;
		while (i < 3)
		{
			if (line[i] && line[i] != '\t')
				return (1);
			i++;
		}
		if (!(line[i] == '+' || line[i] == '-' || ft_isdigit(line[i])))
			return (1);
		i++;
		while (line[i] != '.' || line[i] != ' ')
		{
			if (!(ft_isdigit(line[i])))
				return (1);
			i++;
		}
		if (line[i] == '.')
		{
			i++;
			while (line[i] != ' ')
			{
				if (!(ft_isdigit(line[i])))
					return (1);
			}
		}
	}
	return (0);
}

int		ft_get_cam(t_lstline *list, t_rtv1 *rtv1)
{

	if (list->line && (ft_strcmp(list->line, "\t###cam") == 0))
		list = list->next;
	else
	{
		ft_putstr("scene syntaxe error line 2");
		return (1);
	}
	

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
	{
		ft_putendl(line);
		list = ft_add_list(list, line);
	}
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
