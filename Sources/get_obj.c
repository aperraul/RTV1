/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 14:54:28 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/19 12:22:50 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_get_obj_val(t_rtv1 *rtv1, int type, t_lstline **list, int *line_nb)
{
	if (type == 2)
		return (ft_get_spot(rtv1, list, line_nb));
//	else if (type == 3)
//		return (ft_get_sphere(rtv1, list, line_nb));
//	else if (type == 4)
//		return (ft_get_cylindre(rtv1, list, line_nb));
//	else if (type == 5)
//		return (ft_get_cone(rtv1, list, line_nb));
//	else if (type == 6)
//		return (ft_get_plan(rtv1, list, line_nb));
//	else if (type == 7)
//		return (ft_get_cube(rtv1, list, line_nb));
	return (1);
}

int		ft_strcheck(char *str)
{
	if (ft_strcmp(str, "#End#") == 0)
		return (1);
	else if (ft_strncmp(str, "\t\t##spot ", 9) == 0)
		return (2);
//	else if (ft_strncmp(str, "\t\t##sphere ", 11) == 0)
//		return (3);
//	else if (ft_strncmp(str, "\t\t##cylindre ", 13) == 0)
//		return (4);
//	else if (ft_strncmp(str, "\t\t##cone ", 9) == 0)
//		return (5);
//	else if (ft_strncmp(str, "\t\t##plan ", 9) == 0)
//		return (6);
//	else if (ft_strncmp(str, "\t\t##cube ", 9) == 0)
//		return (7);
	else
		return (0);
}

int		ft_get_obj(t_lstline **list, t_rtv1 *rtv1, int *line_nb)
{
	int		type;

	type = 0;
	if ((*list)->line && (*line_nb += 1) &&
			(ft_strcmp((*list)->line, "\t###Objects")) != 0)
		return (ft_syntaxe_error(*line_nb));
	*list = (*list)->next;
	while ((*line_nb += 1) && (type = ft_strcheck((*list)->line)) > 1)
	{
		if (ft_get_obj_val(rtv1, type, list, line_nb) != 0)
			return (ft_syntaxe_error(*line_nb));
		*list = (*list)->next;
	}
	if (type == 0)
	{
		ft_putendl("SLT");
		return (ft_syntaxe_error(*line_nb));
	}
	return (0);
}
