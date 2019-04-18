/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:12:24 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 16:46:14 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <math.h>

# define MATRIX_ADDITION_ERR 0
# define MATRIX_SUBSTRACTION_ERR 1
# define MATRIX_MULTIPLICATION_ERR 2
# define MATRIX_TRANSPOSE_ERR 3
# define MATRIX_COPY_DATA_ERR 4

# define STAY 0
# define EXIT 1

# define AXIS_X 0
# define AXIS_Y 1
# define AXIS_Z 2

# define IDENTITY 0x7FFFFFFF

typedef struct	s_mat4f
{
	float		mat4f[16];
}				t_mat4f;

typedef struct	s_vec4f
{
	float		vec4f[4];
}				t_vec4f;

typedef struct	s_vec3f
{
	float		vec3f[3];
}				t_vec3f;

/*
** Matrices
*/
t_mat4f			mat4f_add(t_mat4f a, t_mat4f b);
t_mat4f			mat4f_copy(t_mat4f *a, t_mat4f b);
t_mat4f			mat4f_mult(t_mat4f a, t_mat4f b);
t_mat4f			mat4f_axis_rotate(t_mat4f m, int axis, float angle);
void			set_z_axis_rotation_mat4f(t_mat4f *m, float theta);
void			set_y_axis_rotation_mat4f(t_mat4f *m, float theta);
void			set_x_axis_rotation_mat4f(t_mat4f *m, float theta);
t_mat4f			mat4f_scale(t_mat4f m, float f);
void			mat4f_setter(t_mat4f *m, float f);
t_mat4f			mat4f_sub(t_mat4f a, t_mat4f b);
t_mat4f			mat4f_transpose(t_mat4f m);

/*
** Vectors
*/
t_vec3f			vec3f_add(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_copy(t_vec3f *a, t_vec3f *b);
t_vec3f			vec3f_cross(t_vec3f a, t_vec3f b);
float			vec3f_dot(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_float_mult(t_vec3f v, float f);
float			vec3f_magnitude(t_vec3f v);
t_vec3f			vec3f_mul(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_normalize(t_vec3f v);
t_vec3f			vec3f_rotate(t_vec3f v, t_vec3f a);
void			rotate_z_axis(t_vec3f *b, t_vec3f v, t_vec3f a);
void			rotate_y_axis(t_vec3f *b, t_vec3f v, t_vec3f a);
void			rotate_x_axis(t_vec3f *b, t_vec3f v, t_vec3f a);
t_vec3f			vec3f_scale(t_vec3f v, float f);
void			vec3f_setter(t_vec3f *v, float f);
t_vec3f			vec3f_sub(t_vec3f a, t_vec3f b);
t_vec4f			new_vec4f(float x, float y, float z, float w);
t_vec3f			new_vec3f(float x, float y, float z);

#endif
