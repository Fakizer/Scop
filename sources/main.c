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
        if (ft_strstr(scene, "v ")) {
            char_vect = ft_strsplit(scene, ' ');
            data[i].v1 = atoi(char_vect[1]);
            data[i].v2 = atoi(char_vect[2]);
            data[i].v3 = atoi(char_vect[3]);
            i++;
        }
		free(scene);
	}
    if (scene != NULL) {
        free(scene);
    }
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
            data[i].dot1 = atof(char_vect[1]);
            data[i].dot2 = atof(char_vect[2]);
            data[i].dot3 = atof(char_vect[3]);
            i++;
        }
		free(scene);
	}
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

void    pointer_struct_creater() {

}

void    parser(char *filename, t_main  *main_data) {
    char		*scene;
    int         size_v = 0;
    int         size_f = 0;

	size_v = counter(filename, "v ");
    main_data->v = (t_v*)malloc(sizeof(t_v) * size_v);
    set_data_v(filename, "v ", main_data->v);

    size_f = counter(filename, "f ");
    main_data->f = (t_f*)malloc(sizeof(t_f) * size_f);
    set_data_f(filename, "f ", main_data->f);

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
    createImage(1920, 1080);
    printf("%s\n", "--------------- End     program ---------------");
    return 0;
}