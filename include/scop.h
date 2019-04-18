/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:18:00 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 19:20:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "libmath.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include <OpenGL/gl3.h>
# include <GLFW/glfw3.h>

# define OPENGL_VERSION "4.0"

# define BUFFER_SIZE 128
# define COOLDOWN 20
# define WINDOW_W 1280
# define WINDOW_H 1024
# define CAMERA_FOV 90
# define CAMERA_NEAR 0.001
# define CAMERA_FAR 100.0

/*
** Camera zoom
*/
# define ZP GLFW_KEY_KP_ADD
# define ZM GLFW_KEY_KP_SUBTRACT

/*
** Camera movement
*/
# define CF GLFW_KEY_W
# define CB GLFW_KEY_S
# define CL GLFW_KEY_A
# define CR GLFW_KEY_D
# define CU GLFW_KEY_LEFT_SHIFT
# define CD GLFW_KEY_LEFT_CONTROL

/*
** Model movement
*/
# define TF GLFW_KEY_I
# define TB GLFW_KEY_K
# define TL GLFW_KEY_J
# define TR GLFW_KEY_L
# define TU GLFW_KEY_PAGE_UP
# define TD GLFW_KEY_PAGE_DOWN
# define RM GLFW_KEY_MINUS
# define RP GLFW_KEY_EQUAL

/*
** Modifiers
*/
# define MW GLFW_KEY_1
# define MS GLFW_KEY_2
# define MG GLFW_KEY_3
# define MM GLFW_KEY_4
# define MC GLFW_KEY_C
# define MF GLFW_KEY_R
# define MT GLFW_KEY_T
# define MQ GLFW_KEY_Q

# define MAX_KEYS 348

# define FREE 0
# define LOCKED 1

typedef struct		s_texture
{
	unsigned char	*img;
	int				size;
	int				w;
	int				h;
	int				sl;
	short			bpp;
	short			opp;
}					t_texture;

typedef struct		s_cam
{
	t_vec3f			pos;
	t_vec3f			dir;
	t_vec3f			target;
	t_vec3f			up;
	t_vec3f			right;
	t_vec3f			front;
	t_vec3f			inertia;
	float			fov;
	float			velocity;
}					t_cam;

typedef struct		s_key
{
	short			code;
	short			cooldown;
}					t_key;

typedef struct		s_sim
{
	t_mat4f			model;
	t_mat4f			view;
	t_mat4f			projection;
	t_mat4f			mvp;
}					t_sim;

typedef struct		s_buffer
{
	GLuint			vao;
	GLuint			vbo;
	GLuint			ebo;
	GLuint			texture;
}					t_buffer;

typedef struct		s_shader
{
	GLuint			program;
	GLint			mvploc;
	GLint			cmdloc;
	GLint			smdloc;
	GLint			tmdloc;
	GLint			gmdloc;
	GLint			mmdloc;
	GLint			texloc;
}					t_shader;

typedef struct		s_win
{
	GLFWwindow		*glwin;
	int				w;
	int				h;
	float			ratio;
}					t_win;

typedef struct		s_mod
{
	short			wireframe;
	short			focus;
	short			shading;
	short			color;
	short			greyscale;
	short			mapping;
	short			texture;
	short			animation;
}					t_mod;

typedef struct		s_model
{
	t_mat4f			translation;
	t_mat4f			rotation;
	GLfloat			*vertices;
	GLuint			*indices;
	unsigned int	size_indices;
	unsigned int	size_vertices;
	unsigned int	num_indices;
	t_vec3f			center_axis;
	t_vec3f			inertia;
	t_texture		texture;
	float			velocity;
	char			*filename;
}					t_model;

typedef struct		s_scp
{
	t_win			win;
	t_sim			sim;
	t_cam			cam;
	t_key			key[MAX_KEYS];
	t_model			model;
	t_mod			mod;
	t_buffer		buffer;
	t_shader		shader;
}					t_scop;

void				init(t_scop *scop, int argc, char **argv);
void				cicle(t_scop scop);

void				load_obj(t_scop *s, char *filename);
void				load_bmp(t_scop *scop, char *filename);
void				build_shader_program(t_scop *scop);
void				buffering(t_scop *scop, int mode);
void				looper(void);
void				update_shaders(t_scop *scop);

void				display_help(void);
void				error(char *info);
void				free_glfw(t_scop *scop);
int					ft_array_len(void **tab);
GLuint				*gluint_array_copy(GLuint *array, int length, int m);

void				set_projection_matrix(t_scop *scop, float fov);
void				calc_mvp_matrix(t_scop *scop);

void				key_handle(t_scop *scop);
void				camera_zoom(t_scop *scop);
void				camera_move_inertia(t_scop *s, float inertia, int mode);
void				camera_center(t_scop *scop);
void				camera_look_at_target(t_scop *scop);
void				model_move_demo(t_scop *scop);
void				model_move_inertia(t_scop *scop, float inertia);

#endif
