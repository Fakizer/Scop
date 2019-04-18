/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:33:55 by wwatkins          #+#    #+#             */
/*   Updated: 2019/04/17 19:42:24 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_glfw_scop(void)
{
	if (!glfwInit())
		ft_putstr("ERROR: glfw initialization failed.");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ft_atoi(&OPENGL_VERSION[0]));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ft_atoi(&OPENGL_VERSION[2]));
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void	init_glfw_win(t_scop *scop)
{
	int width;
	int height;

	scop->win.glwin = glfwCreateWindow(scop->win.w, scop->win.h,
										"scop", NULL, NULL);
	glfwMakeContextCurrent(scop->win.glwin);
	glfwGetFramebufferSize(scop->win.glwin, &width, &height);
	glViewport(0, 0, width, height);
	glfwSetInputMode(scop->win.glwin, GLFW_STICKY_KEYS, 1);
}

void	init_matrix(t_scop *scop)
{
	scop->mod.animation = 0;
	mat4f_setter(&scop->sim.model, IDENTITY);
	mat4f_setter(&scop->sim.view, IDENTITY);
	set_projection_matrix(scop, scop->cam.fov);
	mat4f_setter(&scop->model.rotation, IDENTITY);
	mat4f_setter(&scop->model.translation, IDENTITY);
	vec3f_setter(&scop->model.inertia, 0);
	vec3f_setter(&scop->model.center_axis, 0);
}

void	init_camera(t_scop *scop)
{
	t_vec3f	up;

	up = new_vec3f(0, 1, 0);
	scop->cam.pos = new_vec3f(0, 0, 3);
	scop->cam.target = new_vec3f(0, 0, 0);
	scop->cam.dir = vec3f_normalize(vec3f_sub(scop->cam.pos, scop->cam.target));
	scop->cam.right = vec3f_normalize(vec3f_cross(up, scop->cam.dir));
	scop->cam.up = vec3f_cross(scop->cam.dir, scop->cam.right);
	scop->cam.front = vec3f_cross(scop->cam.up, scop->cam.right);
	vec3f_setter(&scop->cam.inertia, 0);
	scop->cam.velocity = 0.005;
}

void	init(t_scop *scop, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < MAX_KEYS)
		scop->key[i].cooldown = 0;
	if (argc == 2 && ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".obj") == 0)
		scop->model.filename = argv[1];
	else
		display_help();
	scop->cam.fov = CAMERA_FOV;
	scop->win.w = WINDOW_W;
	scop->win.h = WINDOW_H;
	scop->win.ratio = scop->win.w / (float)scop->win.h;
	init_glfw_scop();
	init_glfw_win(scop);
	init_camera(scop);
	init_matrix(scop);
	scop->mod.wireframe = GL_FILL;
	scop->mod.shading = 0;
	scop->mod.focus = 1;
	scop->mod.color = 0;
	scop->mod.greyscale = 0;
	scop->mod.mapping = 0;
	scop->mod.texture = 0;
	scop->model.velocity = 0.33;
}
