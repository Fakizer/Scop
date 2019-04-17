#include "scop.h"

t_face      *new_face(char **char_vect)
{
    int j;
    t_face  *face = NULL;
    char    **vun;

    j = 0;
    face = (t_face*)malloc(sizeof(t_face));
    // face->n_verts = ft_words(scene, ' ') - 1;

    face->n_verts = 3;
    face->verts = NULL;
    face->uv = NULL;
    face->norms = NULL;
    face->verts = (int*)malloc(sizeof(int) * face->n_verts);
    face->uv = (int*)malloc(sizeof(int) * face->n_verts);
    face->norms = (int*)malloc(sizeof(int) * face->n_verts);
    if (ft_strchr(char_vect[0], '/') != NULL) {
        while (j < face->n_verts)
        {
            vun = ft_strsplit(char_vect[j], '/');
            face->verts[j] = atoi(vun[0]) - 1;
            face->uv[j] = atoi(vun[1]) - 1;
            face->norms[j] = atoi(vun[2]) - 1;
            j++;
        }
    }
    // else
    // {
    //     while (j < face->n_verts)
    //     {
    //         face->verts[j] = atoi(char_vect[j]) - 1;
    //         // face->uv[j] = atoi(char_vect[1]) - 1;
    //         // face->norms[j] = atoi(char_vect[2]) - 1;
    //         j++;
    //     }
    // }
    
    return (face);
}

int     	*int_array_copy(int *array, int length, int m)
{
	int		i;
	int	*new;

	i = -1;
	new = (int*)malloc(sizeof(int) * length);
	while (++i < length - m)
		new[i] = array[i];
	free(array);
	array = new;
	return (new);
}

int		array_len(void **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int     *append_indices(int *array, char *line, int *length)
{
    int		j;
	int		m;
	char	**tab;

    // printf("%s\n", line);
	tab = ft_strsplit(&line[1], ' ');
	m = array_len((void**)tab) == 4 ? 6 : 3;
	*length += m;
    // printf("%d | %d\n", *length, m);
	array = int_array_copy(array, *length, m);
    // for (int i = 0; i < *length; i++) {
    //     printf("| %d | ", array[i]);
    //     if (*length - i == 1)
    //         printf("\n");
    // }
	j = -1;
	while (++j < 3)
	{
		array[*length - m + j] = ft_atoi(tab[j]) - 1;
        // printf("%d | ", array[*length - m + j]);
		if (m == 6) {
			array[*length - m + 3 + j] = ft_atoi(tab[j > 0 ? j + 1 : 0]) - 1;
            // printf("%d+ | ", array[*length - m + 3 + j]);
        }
		ft_strdel(&tab[j]);
	}
    // printf("\n");
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
    // printf("--------------------------------------------\n");
	return (array);
}

void    set_data_f(char *filename, char *flag, t_f *fi) {
    char    *scene = NULL;
    int     size = 0;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_face  *face = NULL;
    int f;

    f = 0;
    fd = open(filename, O_RDONLY);
    face = (t_face*)malloc(sizeof(t_face));
    face->n_verts = 3;
    face->verts = (int*)malloc(sizeof(int) * 3);
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) 
        {
            if (ft_strchr(scene, '/') != NULL) {
                // printf("set_data_f------1\n");
                char_vect = ft_strsplit(scene, ' ');
                int n_verts = ft_words(scene, ' ') - 1;
                size = 0;
                *char_vect++;
                if (n_verts > 2)
                {
                    while (size < n_verts - 2)
                    {
                        face = new_face(&char_vect[size]);
                        size++;
                    }
                }
                fi->faces[i] = face;
            }
            else
            {
                face->verts = append_indices(face->verts, scene, &f);
                fi->faces[0] = face;
                fi->n_face = f / 3;
            }
            i++;
        }
		free(scene);
        scene = NULL;
	}

    // for (int i = 0; i < fi->n_face; i++) {
        
    // }
    if (scene != NULL) {
        free(scene);
        scene = NULL;
    }
    close(fd);
}

void    set_data_vt(char *filename, char *flag, t_vt *vt) {
    char    *scene = NULL;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_vect3f *uv;

    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) {
            char_vect = ft_strsplit(scene, ' ');
            uv = new_vect3f(atof(char_vect[1]), atof(char_vect[2]), atof(char_vect[3]));
            vt->uv[i] = uv;
            i++;
        }
		free(scene);
	}
    if (scene != NULL) {
        free(scene);
    }
    close(fd);
}

void    set_data_vn(char *filename, char *flag, t_vn *vn) {
    char    *scene = NULL;
    int     fd = 0;
    int     i = 0;
    char    **char_vect;
    t_vect3f *norm;

    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &scene) > 0)
	{
        if (ft_strstr(scene, flag)) {
            char_vect = ft_strsplit(scene, ' ');
            norm = new_vect3f(atof(char_vect[1]), atof(char_vect[2]), atof(char_vect[3]));
            vn->norms[i] = norm;
            i++;
        }
		free(scene);
	}
    if (scene != NULL) {
        free(scene);
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
    // printf("------------------------1 | %d\n", i);
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
    if (main_data->v->n_vert > 0)
    {
        main_data->v->verts = (t_vect3f**)malloc(sizeof(t_vect3f*) * size_v);
        printf("set_data_v start; main_data->v->verts: memory alocated\n");
        int i = 0;
        set_data_v(filename, "v ", main_data->v);
        printf("set_data_v end; | %d\n\n", main_data->v->n_vert);
    }

    printf("set_data_vn start;\n");
	size_v = counter(filename, "vn ");
    main_data->vn->n_norms = size_v;
    if (main_data->vn->n_norms > 0)
    {
        main_data->vn->norms = (t_vect3f**)malloc(sizeof(t_vect3f*) * size_v);
        printf("set_data_vn start; main_data->vn->norms: memory alocated\n");
        set_data_vn(filename, "vn ", main_data->vn);
        printf("set_data_vn end; | %d\n\n", main_data->vn->n_norms);
    }

    printf("set_data_vt start;\n");
	size_v = counter(filename, "vt ");
    main_data->vt->n_uv = size_v;
    if (main_data->vt->n_uv > 0)
    {
        main_data->vt->uv = (t_vect3f**)malloc(sizeof(t_vect3f*) * size_v);
        printf("set_data_vt start; main_data->vt->uv: memory alocated\n");
        set_data_vt(filename, "vt ", main_data->vt);
        printf("set_data_vt end; | %d\n\n", main_data->vt->n_uv);
    }

    printf("set_data_f start;\n");
    size_f = counter(filename, "f ");
    main_data->f->n_face = size_f;
    main_data->f->faces = (t_face**)malloc(sizeof(t_face*) * size_f);
    printf("set_data_f start; main_data->f->faces: memory alocated\n");
    set_data_f(filename, "f ", main_data->f);
    printf("set_data_f end; | %d\n", main_data->f->n_face);

    printf("# v# %d vn# %d vt# %d f# %d\n", main_data->v->n_vert, 
                                            main_data->vn->n_norms, 
                                            main_data->vt->n_uv,
                                            main_data->f->n_face);

}
