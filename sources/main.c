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

void    set_data_f(char *filename, char *flag, t_f *data) {
    char    *scene;
    int     size = 0;
    int     fd = 0;
    int     ret = 0;
    int     i = 0;
    char    **char_vect;

    fd = open(filename, O_RDONLY);
    while ((ret = get_next_line(fd, &scene)) > 0)
	{
        if (ft_strstr(scene, "f ")) {
            char_vect = ft_strsplit(scene, ' ');
            int j = 0;
            int len = ft_words(scene, ' ') - 1;
            data->n_verts = len;
            data->verts = (int*)malloc(sizeof(int) * len);
            while (j < len)
            {
                data->verts[j] = atoi(char_vect[j+1]);
                j++;
            }
            i++;
        }
		free(scene);
	}
    if (scene != NULL) {
        free(scene);
    }
    printf("set_data_f\n");
    close(fd);
}

void    set_data_v(char *filename, char *flag, t_v *data) {
    char    *scene;
    int     size = 0;
    int     fd = 0;
    int     ret = 0;
    int     i = 0;
    char    **char_vect;

    fd = open(filename, O_RDONLY);
    while ((ret = get_next_line(fd, &scene)) > 0)
	{
        if (ft_strstr(scene, "v ")) {
            char_vect = ft_strsplit(scene, ' ');
            int j = 0;
            int len = ft_words(scene, ' ') - 1;
            data->dots = (float*)malloc(sizeof(float) * len);
            if (data->dots == NULL)
                printf("data->dots = NULL\n");
            while (j < len)
            {
                data->dots[j] = atof(char_vect[j+1]);
                printf("%f\n", data->dots[0]);
                j++;
            }
            i++;
        }
		free(scene);
	}
    if (scene != NULL) {
        free(scene);
    }
    printf("set_data_v\n");
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

void    pointer_struct_creater() {

}

void    parser(char *filename, t_main  *main_data) {
    char		*scene;
    int         size_v = 0;
    int         size_f = 0;

	size_v = counter(filename, "v ");
    main_data->n_vert = size_v;
    main_data->v = (t_v*)malloc(sizeof(t_v) * size_v);
    set_data_v(filename, "v ", main_data->v);

    // printf("%f\n", main_data->v[0]->dots[0]);

    size_f = counter(filename, "f ");
    main_data->n_face = size_f;
    main_data->f = (t_f*)malloc(sizeof(t_f) * size_f);
    set_data_f(filename, "f ", main_data->f);

    printf("%d\n", main_data->f[2].verts[0]);

    printf("# v# %d f# %d\n", size_v, size_f);
}

int main(int argc, char** argv) 
{
    t_main  *main_data;

    printf("%s\n", "--------------- Start   program ---------------");
    if ((main_data = (t_main*)malloc(sizeof(t_main))) == NULL) {
        printf("%s\n", "false malloc");
    }
    pointer_struct_creater();
    parser(argv[1], main_data);
    createImage(1920, 1080, main_data);
    printf("%s\n", "--------------- End     program ---------------");
    return 0;
}