/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:29:19 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/04/17 17:32:14 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLfloat	*vertices_pushback(GLfloat *array, const char *line, int *length)
{
	int		i;
	int		j;
	char	**tab;
	GLfloat	*new;

	tab = ft_strsplit(&line[1], ' ');
	*length += 6;
	new = (GLfloat*)malloc(sizeof(GLfloat) * *length);
	i = -1;
	while (++i < *length - 6)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (tab[++j] != NULL)
	{
		array[*length - 6 + j] = (GLfloat)ft_atof(tab[j]);
		array[*length - 3 + j] = j * 0.66f;
	}
	j = -1;
	while (tab[j] != NULL)
		free(tab[++j]);
	free(tab);
	tab = NULL;
	return (array);
}

GLuint	*indices_pushback(GLuint *array, char *line, int *length)
{
	int		j;
	int		m;
	char	**tab;

	tab = ft_strsplit(&line[1], ' ');
	m = ft_array_len((void**)tab) == 4 ? 6 : 3;
	*length += m;
	array = gluint_array_copy(array, *length, m);
	j = -1;
	while (++j < 3)
	{
		array[*length - m + j] = (GLuint)ft_atoi(tab[j]) - 1;
		if (m == 6)
			array[*length - m + 3 + j] =
			(GLuint)ft_atoi(tab[j > 0 ? j + 1 : 0]) - 1;
	}
	j = -1;
	while (tab[j] != NULL)
		free(tab[++j]);
	free(tab);
	tab = NULL;
	return (array);
}

t_vec3f	compute_center_axis(GLfloat *vertices, int num_vertices)
{
	int		i;
	t_vec3f	max;
	t_vec3f	min;
	t_vec3f	center;

	i = 0;
	max = new_vec3f(0, 0, 0);
	min = new_vec3f(0, 0, 0);
	while (i < num_vertices - 6)
	{
		vertices[i] > max.vec3f[0] ? max.vec3f[0] = vertices[i] : 0;
		vertices[i] < min.vec3f[0] ? min.vec3f[0] = vertices[i] : 0;
		vertices[i + 1] > max.vec3f[1] ? max.vec3f[1] = vertices[i + 1] : 0;
		vertices[i + 1] < min.vec3f[1] ? min.vec3f[1] = vertices[i + 1] : 0;
		vertices[i + 2] > max.vec3f[2] ? max.vec3f[2] = vertices[i + 2] : 0;
		vertices[i + 2] < min.vec3f[2] ? min.vec3f[2] = vertices[i + 2] : 0;
		i += 6;
	}
	center = vec3f_float_mult(vec3f_add(max, min), 0.5);
	return (center);
}

void	center_vertices(t_scop *scop, int length)
{
	int		i;
	float	tx;
	float	theta;

	i = 0;
	theta = 90 * (M_PI / 180);
	while (i < length)
	{
		scop->model.vertices[i] -= scop->model.center_axis.vec3f[0];
		scop->model.vertices[i + 1] -= scop->model.center_axis.vec3f[1];
		scop->model.vertices[i + 2] -= scop->model.center_axis.vec3f[2];
		tx = scop->model.vertices[i] * cos(theta) -
			scop->model.vertices[i + 2] * sin(theta);
		scop->model.vertices[i + 2] = scop->model.vertices[i] * sin(theta) +
			scop->model.vertices[i + 2] * cos(theta);
		scop->model.vertices[i] = tx;
		i += 6;
	}
	scop->model.center_axis = new_vec3f(0, 0, 0);
}

void	load_obj(t_scop *s, char *filename)
{
	int		fd;
	int		v;
	int		f;
	char	*scene;

	v = 0;
	f = 0;
	s->model.vertices = (GLfloat*)malloc(sizeof(GLfloat) * 3);
	s->model.indices = (GLuint*)malloc(sizeof(GLuint) * 3);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error("obj file opening failed.");
	while (get_next_line(fd, &scene) > 0)
	{
		if (ft_strstr(scene, "v "))
			s->model.vertices = vertices_pushback(s->model.vertices, scene, &v);
		else if (ft_strstr(scene, "f "))
			s->model.indices = indices_pushback(s->model.indices, scene, &f);
		ft_strdel(&scene);
	}
	ft_strdel(&scene);
	s->model.size_vertices = v * sizeof(GLfloat);
	s->model.size_indices = f * sizeof(GLuint);
	s->model.num_indices = f;
	s->model.center_axis = compute_center_axis(s->model.vertices, v);
	center_vertices(s, v);
}
