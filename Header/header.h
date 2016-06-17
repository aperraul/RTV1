/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 13:04:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/17 16:56:57 by aperraul         ###   ########.fr       */
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
	double		posx;
	double		posy;
	double		posz;
	t_vector	dir;
}				t_cam;

typedef struct	s_spot
{
	double		posx;
	double		posy;
	double		posz;
	int			lux;
}				t_spot;

typedef struct	s_sphere
{
	double		posx;
	double		posy;
	double		posz;
	double		r;
	int			color;
	t_vector	rot;
}				t_sphere;

typedef struct	s_cylindre
{
	double		posx;
	double		posy;
	double		posz;
	double		base_size;
	double		height;
	int			color;
	t_vector	rot;
}				t_cylindre;

typedef struct	s_plan
{
	double		posx;
	double		posy;
	double		posz;
	double		withd;
	double		height;
	int			color;
	t_vector	rot;
}				t_plan;

typedef struct	s_cone
{
	double		posx;
	double		posy;
	double		posz;
	double		base_size;
	double		height;
	int			color;
	t_vector	rot;
}				t_cone;

typedef struct	s_cube
{
	double		posx;
	double		posy;
	double		posz;
	double		size;
	int			color;
	t_vector	rot;
}				t_cube;

typedef struct	s_object
{
	t_spot		*spot;
	t_sphere	*sphere;
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
t_rtv1			*ft_rtv1_init(void);
void			ft_get_scene(t_rtv1 *rtv1, int ret);
int				ft_scene(t_lstline *list, t_rtv1 *rtv1, int *line_nb);
int				ft_get_cam(t_lstline **list, t_rtv1 *rtv1, int *line_nb);
int				ft_get_obj(t_lstline **list, t_rtv1 *rtv1, int *line_nb);
char			**ft_get_3d_val(char *line);
int				ft_check_3d_value(char *tab);
int				ft_syntaxe_error(int line_nb);
int				ft_strcheck(char *str);
int				ft_get_obj_val(t_rtv1 *rtv1, int type, t_lstline *list);
int				ft_get_spot(t_rtv1 *rtv1, t_lstline *list);
int				ft_get_sphere(t_rtv1 *rtv1, t_lstline *list);
int				ft_get_cylindre(t_rtv1 *rtv1, t_lstline *list);
int				ft_get_cone(t_rtv1 *rtv1, t_lstline *list);
int				ft_get_plan(t_rtv1 *rtv1, t_lstline *list);
int				ft_get_cube(t_rtv1 *rtv1, t_lstline *list);
void			ft_del_rtv1(t_rtv1 *rtv1);

#endif
