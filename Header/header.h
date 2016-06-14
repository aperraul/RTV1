/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 13:04:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/14 13:04:50 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../gnl/get_next_line.h"
# include "../Libgraph/libgraph.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "../SDL2-2.0.4/include/SDL.h"

typedef struct	s_cam
{
	t_3dptd		pos;
	t_vector	dir;
}				t_cam;

typedef struct	s_spot
{
	t_3dptd		pos;
	int			lux;
}				t_spot;

typedef struct	s_sphere
{
	t_3dptd		pos;
	double		r;
	int			color;
	t_vector	rot;
}				t_sphere;

typedef struct	s_cylindre
{
	t_3dptd		pos;
	double		base_size;
	double		height;
	int			color;
	t_vector	rot;
}				t_cylindre;

typedef struct	s_plan
{
	t_3dptd		pos;
	t_ptd		size;
	int			color;
	t_vector	rot;
}				t_plan;

typedef struct	s_cone
{
	t_3dptd		pos;
	double		base_size;
	double		height;
	int			color;
	t_vector	rot;
}				t_cone;

typedef struct	s_cube
{
	t_3dptd		pos;
	double		size;
	int			color;
	t_vector	rot;
}				t_cube;

typedef struct	s_object
{
	t_spot		*spot;
	t_sphere	*shere;
	t_cylindre	*cylindre;
	t_plan		*plan;
	t_cone		*cone;
	t_cube		*cube;
}				t_object;

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
	t_object	obj;
}				t_rtv1;

int				main(int argc, char **argv);
t_rtv1			ft_rtv1_init(void);

#endif
