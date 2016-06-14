/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 14:57:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/14 11:04:16 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_ptd
{
	double		x;
	double		y;
}				t_ptd;

typedef struct	s_ptf
{
	float		x;
	float		y;
}				t_ptf;

typedef struct	s_ptll
{
	long long	x;
	long long	y;
}				t_ptll;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_line
{
	t_pt		start;
	t_pt		end;
	int			dx;
	int			dy;
}				t_line;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_pt		pos;
}				t_matrix;

typedef struct	s_matrix_rot
{
	t_matrix	mx;
	t_matrix	my;
	t_matrix	mz;
	t_matrix	m;
}				t_matrix_rot;

typedef struct	s_3dpt
{
	int			x;
	int			y;
	int			z;
}				t_3dpt;

typedef struct	s_3dptd
{
	double		x;
	double		y;
	double		z;
}				t_3dptd;

t_pt			ft_make_pt(int x, int y);
t_pt			ft_apply_matrix(t_3dpt pt, t_matrix m);
t_3dpt			ft_make_3dpt(int x, int y, int z);
t_3dptd			ft_make_3dptd(double x, double y, double z);
t_line			ft_make_line(int x1, int y1, int x2, int y2);
t_vector		ft_make_vector(float x, float y, float z);
t_matrix		ft_make_matrix_x(float rad);
t_matrix		ft_make_matrix_y(float rad);
t_matrix		ft_make_matrix_z(float rad);
t_matrix		ft_multiply_matrix(t_matrix m1, t_matrix m2);
t_matrix		ft_init_matrix(t_pt pos);
t_rgb			ft_hexa_to_rgb(int hexa);
int				ft_rgb_to_hexa(t_rgb rgb);

#endif
