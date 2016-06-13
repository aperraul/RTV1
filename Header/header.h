/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:08:05 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/13 12:41:02 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../Libdraw/libdraw.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "../SDL2-2.0.4/include/SDL.h"

typedef struct	s_cam
{
	double		x;
	double		y;
	double		z;
}				t_cam;

typedef struct	s_sphere
{
	t_ptd		pos;
	double		r;
	int			color;
}				t_sphere;

typedef struct	s_cylindre
{
	t_ptd		pos;
	double		base_size;
	double		height;
	int			color;
}				t_cylindre;

typedef struct	s_plan
{
	t_ptd	pos;
	t_ptd	size;
	int		color;
}

typedef struct	s_cone
{
	t_ptd		pos;
	double		base_size;
	double		height;
	int			color;
}

typedef struct	s_geo_form
{
	t_sphere	shere;
	t_cylindre	cylindre;
	t_plan		plan;
	t_cone		cone;
}				t_geo_form;

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Surface		*img;
	int				withd;
	int				height;
	SDL_Event		*event;
}				t_env;

typedef struct	s_rtv1
{
	t_env		*env;
	t_cam		cam;
}				t_rtv1;

int				main(int argc, char **argv);
