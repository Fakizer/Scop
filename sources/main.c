/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:00:15 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/03/28 14:25:00 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

const int bytesPerPixel = 3; /// red, green, blue
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;

void    set_data_f(char *filename, char *flag, t_f *f) {
    char    *scene;
    int     size = 0;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_face  *face;

    fd = open(filename, O_RDONLY);
    face = (t_face*)malloc(sizeof(t_face));
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) 
        {
            char_vect = ft_strsplit(scene, ' ');
            face->n_verts = ft_words(scene, ' ') - 1;
            face->verts = (int*)malloc(sizeof(int) * face->n_verts);
            int j = 0;
            while (j < face->n_verts)
            {
                face->verts[j] = atoi(char_vect[j+1]) - 1;
                printf("%d | ", face->verts[j]);
                j++;
            }
            printf("\n\n");
            f->faces[i] = face;
            i++;
        }
		free(scene);
	}
    printf("------------------------1 | %d\n", i);
    if (scene != NULL) {
        free(scene);
    }
    close(fd);
}

void    set_data_v(char *filename, char *flag, t_v *v) {
    char    *scene;
    int     size = 0;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_vert *vert;

    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) {
            char_vect = ft_strsplit(scene, ' ');
            vert = (t_vert*)malloc(sizeof(t_vert));
            vert->n_dots = ft_words(scene, ' ') - 1;
            vert->dots = (float*)malloc(sizeof(float) * vert->n_dots);
            int j = 0;
            while (j < vert->n_dots)
            {
                vert->dots[j] = atof(char_vect[j+1]);
                j++;
            }
            v->verts[i] = vert;
            i++;
        }
		free(scene);
	}
    printf("------------------------1 | %d\n", i);
    if (scene != NULL) {
        free(scene);
    }
    close(fd);
}

int     counter(char *filename, char *flag) {
    char    *scene;
    int     size = 0;
    int     fd = 0;
    int     ret = 0;

    fd = open(filename, O_RDONLY);
	while ((ret = get_next_line(fd, &scene)) > 0)
	{
        if (ft_strstr(scene, flag)) {
            size++;
        }
        if (scene != NULL) {
		    free(scene);
        }
	}
    if (scene != NULL) {
        free(scene);
    }
	close(fd);
    return (size);
}

void    parser(char *filename, t_main  *main_data) {
    char		*scene;
    int         size_v = 0;
    int         size_f = 0;

    printf("set_data_v start;\n");
	size_v = counter(filename, "v ");
    main_data->v->n_vert = size_v;
    main_data->v->verts = (t_vert**)malloc(sizeof(t_vert*) * size_v);
    int i = 0;
    set_data_v(filename, "v ", main_data->v);
    printf("set_data_v end; | %d\n", main_data->v->n_vert);

    printf("set_data_f start;\n");
    size_f = counter(filename, "f ");
    main_data->f->n_face = size_f;
    main_data->f->faces = (t_face**)malloc(sizeof(t_face*) * size_f);
    i = 0;
    set_data_f(filename, "f ", main_data->f);
    printf("set_data_f end; | %d\n", main_data->f->n_face);

    printf("# v# %d f# %d\n", size_v, size_f);
}

t_main      *init_data(int width, int height) {
    t_main  *data;

    if ((data = (t_main*)malloc(sizeof(t_main))) == NULL) {
        printf("%s\n", "false malloc");
    }

    data->data = (unsigned char*)malloc(sizeof(unsigned char) * (height * width * bytesPerPixel));
    data->v = (t_v*)malloc(sizeof(t_v));
    data->f = (t_f*)malloc(sizeof(t_f));
    data->par = (t_par*)malloc(sizeof(t_par));
    data->par->height = height;
    data->par->width = width;

    return (data);
}

int main(int argc, char** argv) 
{
    t_main  *main_data;

    printf("%s\n", "--------------- Start   program ---------------");
    main_data = init_data(50, 50);
    parser(argv[1], main_data);
    createImage(main_data);
    printf("%s\n", "--------------- End     program ---------------");
    return 0;
}