#include "scop.h"

void    set_data_f(char *filename, char *flag, t_f *f) {
    char    *scene = NULL;
    int     size = 0;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_face  *face = NULL;

    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) 
        {
            char_vect = ft_strsplit(scene, ' ');
            face = (t_face*)malloc(sizeof(t_face));
            face->n_verts = ft_words(scene, ' ') - 1;
            face->verts = NULL;
            face->verts = (int*)malloc(sizeof(int) * face->n_verts);
            int j = 0;
            while (j < face->n_verts)
            {
                face->verts[j] = atoi(char_vect[j+1]) - 1;
                j++;
            }
            f->faces[i] = face;
            i++;
        }
		free(scene);
        scene = NULL;
	}
    printf("------------------------1 | %d\n", i);
    if (scene != NULL) {
        free(scene);
        scene = NULL;
    }
    close(fd);
}

void    set_data_v(char *filename, char *flag, t_v *v) {
    char    *scene = NULL;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_vect3f *vert;

    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) {
            char_vect = ft_strsplit(scene, ' ');
            vert = new_vect3f(atof(char_vect[1]), atof(char_vect[2]), atof(char_vect[3]));
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
    main_data->v->verts = (t_vect3f**)malloc(sizeof(t_vect3f*) * size_v);
    printf("set_data_v start; main_data->v->verts: memory alocated\n");
    int i = 0;
    set_data_v(filename, "v ", main_data->v);
    printf("set_data_v end; | %d\n", main_data->v->n_vert);

    printf("set_data_f start;\n");
    size_f = counter(filename, "f ");
    main_data->f->n_face = size_f;
    main_data->f->faces = (t_face**)malloc(sizeof(t_face*) * size_f);
    printf("set_data_v start; main_data->f->faces: memory alocated\n");
    i = 0;
    set_data_f(filename, "f ", main_data->f);
    printf("set_data_f end; | %d\n", main_data->f->n_face);

    // while (i < 249) {
    //     printf("i: %d //", i);
    //     printf("%d | %d | %d\n", main_data->f->faces[i]->verts[0], main_data->f->faces[i]->verts[1], main_data->f->faces[i]->verts[2]);
    //     i++;
    // }

    printf("# v# %d f# %d\n", size_v, size_f);
}
