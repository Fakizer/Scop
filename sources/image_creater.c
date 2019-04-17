#include "scop.h"

void    setter(int x, int y, t_main *main_data, unsigned char *data_color)
{
    // printf("setter();\n");

    int width = main_data->par->width;
    int height = main_data->par->height;

    if (!main_data->data || x < 0 || y < 0 || x >= width || y >= height) {
        // printf("9 ebal\n");
		return ;
	}

    // if (data_color[0] == 0 && data_color[1] == 0 && data_color[2] == 0)
    // {
    //     if (x < width && x > 300)
    //     {
    //         if (y < height && y > 300)
    //             printf("9 ebal\n");
    //     }
    // }
    // printf("x: %d | y: %d | r: %hu | g: %hu | b: %hu\n", x, y, data_color[0], data_color[1], data_color[2]);
    ft_memcpy(main_data->data + (x + y * width) * bytesPerPixel, data_color, bytesPerPixel);
    // memcpy(main_data->data+(x+y*width)*bytesPerPixel, data_color, bytesPerPixel);
}

void    line(int x0, int y0, int x1, int y1, t_main *main_data, unsigned char *data_color)
{
    // printf("line();\n");

    // printf("- x0: %d | y0: %d | x1: %d | y1: %d\n", x0, y0, x1, y1);
    
    int steep = 0;
    if (abs(x0 - x1) < abs(y0 - y1)) {
        int x = x0;
        x0 = y0;
        y0 = x;
        // swap(x0, y0);
        x = x1;
        x1 = y1;
        y1 = x;
        // swap(x1, y1);
        steep = 1;
    }
    if (x0 > x1) {
        int y = x0;
        x0 = x1;
        x1 = y;
        // swap(x0, x1);
        y = y0;
        y0 = y1;
        y1 = y;
        // swap(y0, y1);
    }

    // printf("-- x0: %d | y0: %d | x1: %d | y1: %d\n", x0, y0, x1, y1);

    for (int x = x0; x <= x1; x++) {
        float t = (x - x0) / (float)(x1 - x0);
        int y = y0 * (1.0 - t) + y1 * t;
        if (steep == 1) {
            setter(y, x, main_data, data_color);
        } else {
            setter(x, y, main_data, data_color);
        }
    }
}

void    swap_float(float *f1, float *f2)
{
    float f;

    f = *f1;
    *f1 = *f2;
    *f2 = f;
}

void    swap_vect3i(t_vect3i *t1, t_vect3i *t2)
{
    t_vect3i buff;

    buff = *t1;
    *t1 = *t2;
    *t2 = buff;
}

t_vect3i        calculate_b(t_vect3i t0, t_vect3i t1, t_vect3i t2, int i, int total_height)
{
    int second_half = 0;
    int segment_height = 0;

    if (i > (t1.y - t0.y) || t1.y == t0.y)
            second_half = 1;
    segment_height = second_half == 1 ? t2.y - t1.y : t1.y - t0.y;
    float alpha = (float)i / (float)total_height;
    float beta  = (float)(i - (second_half == 1 ? t1.y - t0.y : 0)) / (float)segment_height;

    t_vect3f t0_f = copy_vect3f(t0.x, t0.y, t0.z); 
    t_vect3f t1_f = copy_vect3f(t1.x, t1.y, t1.z);
    t_vect3f t2_f = copy_vect3f(t2.x, t2.y, t2.z);

    t_vect3f A_f = vectadd_vect3f(t0_f, vectmult_vect3f(vectadd_vect3f(t2_f, negative_vect3f(t0_f)), alpha));
    t_vect3i A = new_vect3i(A_f.x, A_f.y, A_f.z);

    t_vect3f B_buff1_f = vectadd_vect3f(t1_f, vectmult_vect3f(vectadd_vect3f(t2_f, negative_vect3f(t1_f)), beta));
    t_vect3i B_buff1 = new_vect3i(B_buff1_f.x, B_buff1_f.y, B_buff1_f.z);

    t_vect3f B_buff2_f = vectadd_vect3f(t0_f, vectmult_vect3f(vectadd_vect3f(t1_f, negative_vect3f(t0_f)), beta));
    t_vect3i B_buff2 = new_vect3i(B_buff2_f.x, B_buff2_f.y, B_buff2_f.z);
    return (second_half == 1 ? B_buff1 : B_buff2);
}

void    triangle(t_vect3i *t, float *intensity, t_main *main_data, unsigned char *data_color)
{
    // printf("++++++++++++++++++++++++++++++++++\n");
    unsigned char color[3];
    t_vect3i t0 = t[0];
    t_vect3i t1 = t[1];
    t_vect3i t2 = t[2];

    float ity0 = intensity[0];
    float ity1 = intensity[1];
    float ity2 = intensity[2];

    if (t0.y==t1.y && t0.y==t2.y) 
        return;
    if (t0.y>t1.y)
    {
        swap_vect3i(&t0, &t1);
        swap_float(&ity0, &ity1);
    }
    if (t0.y>t2.y) 
    {
        swap_vect3i(&t0, &t2);
        swap_float(&ity0, &ity2);
    }
    if (t1.y>t2.y)
    {
        swap_vect3i(&t1, &t2);
        swap_float(&ity1, &ity2);
    }
    
    int total_height = t2.y - t0.y;

    int i = 0;
    int second_half = 0;
    int segment_height = 0;

    // printf("--------------------41================================= | %d\n", i);
    while (i < total_height)
    {
        if (i > (t1.y - t0.y) || t1.y == t0.y)
            second_half = 1;
        segment_height = second_half == 1 ? t2.y - t1.y : t1.y - t0.y;
        float alpha = (float)i / (float)total_height;
        float beta  = (float)(i - (second_half == 1 ? t1.y - t0.y : 0)) / (float)segment_height; // be careful: with above conditions no division by zero here
        
        t_vect3f t0_f = copy_vect3f(t0.x, t0.y, t0.z); 
        t_vect3f t1_f = copy_vect3f(t1.x, t1.y, t1.z);
        t_vect3f t2_f = copy_vect3f(t2.x, t2.y, t2.z);

        t_vect3f A_f = vectadd_vect3f(t0_f, vectmult_vect3f(vectadd_vect3f(t2_f, negative_vect3f(t0_f)), alpha));
        t_vect3i A = vect3f2vect3i(A_f.x, A_f.y, A_f.z);

        t_vect3f B_buff1_f = vectadd_vect3f(t1_f, vectmult_vect3f(vectadd_vect3f(t2_f, negative_vect3f(t1_f)), beta));
        t_vect3i B_buff1 = vect3f2vect3i(B_buff1_f.x, B_buff1_f.y, B_buff1_f.z);

        t_vect3f B_buff2_f = vectadd_vect3f(t0_f, vectmult_vect3f(vectadd_vect3f(t1_f, negative_vect3f(t0_f)), beta));
        t_vect3i B_buff2 = vect3f2vect3i(B_buff2_f.x, B_buff2_f.y, B_buff2_f.z);

        float ityA = ity0 + (ity2 - ity0) * alpha;
        float ityB = second_half == 1 ? ity1 + (ity2 - ity1) * beta : ity0 + (ity1 - ity0) * beta;

        t_vect3i B = second_half == 1 ? B_buff1 : B_buff2;


        if (A.x > B.x)
        {
            swap_vect3i(&A, &B);
            swap_float(&ityA, &ityB);
        }

        int j = A.x;

        while(j <= B.x)
        {
            float phi = B.x == A.x ? 1. : (float)(j - A.x) / (float)(B.x - A.x);
            t_vect3f A_f = copy_vect3f(A.x, A.y, A.z);
            t_vect3f B_f = copy_vect3f(B.x, B.y, B.z);
            t_vect3f P_buff = vectadd_vect3f(A_f, vectmult_vect3f(vectadd_vect3f(B_f, negative_vect3f(A_f)), phi));
            t_vect3i P = vect3f2vect3i(P_buff.x, P_buff.y, P_buff.z);
            float ityP = ityA  + (ityB-ityA)*phi;
            int idx = P.x + P.y * main_data->par->width;
            // if (P.x >= main_data->par->width || P.y >= main_data->par->height || P.x < 0 || P.y < 0)
            // {
                // printf("triangle continue;\n");
                // continue;
            // }

            if (P.x < main_data->par->width && P.y < main_data->par->height && P.x >= 0 && P.y >= 0)
            {
                if (idx < (main_data->par->width * main_data->par->height) && idx > -1)
                {
                    // printf("bleatb\n");
                    // printf("--------------------42================================= | %d | %d | %d\n\n", i, j, idx);
                    if (main_data->zbuff[idx] < P.z)
                    {
                        main_data->zbuff[idx] = P.z;
                        // printf("%hu | %hu | %hu | %f\n",data_color[0], data_color[1], data_color[2], ityP);
                        ityP = (ityP > 1.f ? 1.f : (ityP < 0.f ? 0.f : ityP));
                        color[0] = (unsigned char)(data_color[0] * ityP);
                        color[1] = (unsigned char)(data_color[1] * ityP);
                        color[2] = (unsigned char)(data_color[2] * ityP);
                        // data_color[0] = (unsigned char)255 * ityP;
                        // data_color[1] = (unsigned char)255 * ityP;
                        // data_color[2] = (unsigned char)255 * ityP;
                        // printf("%hu | %hu | %hu | %f\n\n",color[0], color[1], color[2], ityP);
                        setter(P.x, P.y, main_data, color);
                        // setter(j, t0.y + i, main_data, data_color);
                    }
                }
            }
            j++;
        }

        // printf("--------------------43================================= | %d\n\n", i);
        i++;
    }
}

float           get_vec_coord(t_vect3f v, int i)
{
    return (i<=0 ? v.x : (1==i ? v.y : v.z));
}

t_matrix        lookat(t_vect3f eye, t_vect3f center, t_vect3f up)
{
    t_matrix result;
    t_matrix tr;
    int i;
    t_vect3f z;
    t_vect3f y;
    t_vect3f x;

    z = normalize_vect3f(vectadd_vect3f(eye, negative_vect3f(center)));
    x = normalize_vect3f(crossproduct_vect3f(up, z));
    y = normalize_vect3f(crossproduct_vect3f(z, x));
    // printf("@@@@@@@@@@\n");
    result = identity(4);
    tr = identity(4);

    i = 0;
    while (i < 3)
    {
        result.mat[0][i] = get_vec_coord(x, i);
        result.mat[1][i] = get_vec_coord(y, i);
        result.mat[2][i] = get_vec_coord(z, i);
        tr.mat[i][3] = get_vec_coord(negative_vect3f(center), i);
        i++;
    }

    return (matrix_mult(result, tr));
}

void        normals_no(t_main *main_data, unsigned char *data_color)
{
    t_par *par;
    t_f *modelf;
    t_v *modelv;
    t_vn *modelvn;
    t_vt *modelvt;
    par = main_data->par;
    modelf = main_data->f;
    modelv = main_data->v;
    modelvn = main_data->vn;
    modelvt = main_data->vt;

    t_vect3f light_dir_buff;
    t_vect3f *light_dir;
    t_vect3f *camera_dir;
    t_vect3f *eye;
    t_vect3f *center;
    light_dir_buff = normalize_vect3f(*new_vect3f(-100, 0, -100));
    light_dir = &light_dir_buff;
    // camera_dir = new_vect3f(0, 0, 3);
    eye = new_vect3f(100, 0, 100);
    center = new_vect3f(0, 0, 0);


    t_matrix model_view;
    t_matrix projection;
    t_matrix viewport;
    model_view = lookat(*eye, *center, *new_vect3f(0,1,0));
    projection = identity(4);
    viewport = new_viewport(par->width / 8, par->height / 8, 
                                    par->width * 3 / 4, par->height * 3 / 4);
    projection.mat[3][2] = -1.f / magnitude_vect3f(vectadd_vect3f(*eye, negative_vect3f(*center)));
    t_matrix z = matrix_mult(matrix_mult(viewport, projection), model_view);

    t_vect3i *screen_coords;
    t_vect3f *world_coords;
    float *intensity;
    screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * 3);
    world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * 3);
    intensity = (float*)malloc(sizeof(float) * 3);

    printf("normals_no---------------1 | %d\n", modelf->n_face);
    for (int i = 0; i < modelf->n_face; i++) {
    // for (int i=0; i < 3; i++) {

        // t_vect3i *screen_coords;
        // screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * 3);
        // t_vect3f *world_coords;
        // world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * 3);
        // float *intensity;
        // intensity = (float*)malloc(sizeof(float) * 3);
        
        t_face *face = modelf->faces[0];

        for (int j=0; j<face->n_verts; j++) {

            t_vect3f v = *modelv->verts[face->verts[i * 3 + j]];

            printf("normals_no---------------2 | %d | %d | %d\n", i, j, modelf->n_face);
            // screen_coords[j] = new_vect3i((v->x + 1.) * (float)par->width / 2., 
            //                                 (v->y + 1.) * (float)par->height / 2., 
            //                                 (v->z + 1.) * (float)par->depth / 2.);

            // t_vect3f *v0 = modelv->verts[face->verts[j]];
            // t_vect3f *v1 = modelv->verts[face->verts[(j + 1) % face->n_verts]];

            // int x0 = (v0->x+1.0)*par->width/2.0;
            // int y0 = (v0->y+1.0)*par->height/2.0;
            // int x1 = (v1->x+1.0)*par->width/2.0;
            // int y1 = (v1->y+1.0)*par->height/2.0;

            // line(x0, y0, x1, y1, main_data, data_color);

            t_vect3f buff = m2v(matrix_mult(matrix_mult(matrix_mult(viewport, projection), 
                                                                    model_view), v2m(v)));
            screen_coords[j] = vect3f2vect3i(buff.x, buff.y, buff.z);
            world_coords[j] = v;
            // intensity[j] = dotproduct_vect3f(normalize_vect3f(*modelvn->norms[face->norms[j]]), *light_dir);

            // free(v);
            // v = NULL;
        }

        t_vect3f n = crossproduct_vect3f(vectadd_vect3f(world_coords[2], negative_vect3f(world_coords[0])), 
                                        vectadd_vect3f(world_coords[1], negative_vect3f(world_coords[0])));
        
        n = normalize_vect3f(n);

        intensity[0] = dotproduct_vect3f(n, (*light_dir));
        intensity[1] = dotproduct_vect3f(n, (*light_dir));
        intensity[2] = dotproduct_vect3f(n, (*light_dir));


        // if (intensity > 0) {
            // t_vect2i *uv;
            // uv = (t_vect2i*)malloc(sizeof(t_vect2i) * 3);
            // data_color[2] = (unsigned char)255 * intensity;
            // data_color[1] = (unsigned char)255 * intensity;
            // data_color[0] = (unsigned char)255 * intensity;
        //     triangle(screen_coords, intensity, main_data, data_color);
        // }

        triangle(screen_coords, intensity, main_data, data_color);
        printf("normals_no---------------3 | %d | %d\n", i, modelf->n_face);

        // free(face);
        // face = NULL;
        

        // printf("---------------2 | %d | %d\n", i, modelf->n_face);

    }

    printf("---------------2\n");
    
    free(screen_coords);
    screen_coords = NULL;
    free(world_coords);
    world_coords = NULL;
    free(intensity);
    intensity = NULL;
    printf("---------------3\n");
}

void        normals_yes(t_main *main_data, unsigned char *data_color)
{
    t_par *par;
    t_f *modelf;
    t_v *modelv;
    t_vn *modelvn;
    t_vt *modelvt;
    par = main_data->par;
    modelf = main_data->f;
    modelv = main_data->v;
    modelvn = main_data->vn;
    modelvt = main_data->vt;

    t_vect3f light_dir_buff;
    t_vect3f *light_dir;
    t_vect3f *camera_dir;
    t_vect3f *eye;
    t_vect3f *center;
    light_dir_buff = normalize_vect3f(*new_vect3f(1, -1, 1));
    light_dir = &light_dir_buff;
    camera_dir = new_vect3f(0, 0, 3);
    eye = new_vect3f(1, 1, 3);
    center = new_vect3f(0, 0, 0);


    t_matrix model_view;
    t_matrix projection;
    t_matrix viewport;
    model_view = lookat(*eye, *center, *new_vect3f(0,1,0));
    projection = identity(4);
    viewport = new_viewport(par->width / 8, par->height / 8, 
                                    par->width * 3 / 4, par->height * 3 / 4);
    projection.mat[3][2] = -1.f / magnitude_vect3f(vectadd_vect3f(*eye, negative_vect3f(*center)));
    t_matrix z = matrix_mult(matrix_mult(viewport, projection), model_view);

    t_vect3i *screen_coords;
    t_vect3f *world_coords;
    float *intensity;
    screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * 3);
    world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * 3);
    intensity = (float*)malloc(sizeof(float) * 3);

    printf("---------------1 | %d\n", modelf->n_face);
    for (int i=0; i < modelf->n_face; i++) {
    // for (int i=0; i < 3; i++) {

        // t_vect3i *screen_coords;
        // screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * 3);
        // t_vect3f *world_coords;
        // world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * 3);
        // float *intensity;
        // intensity = (float*)malloc(sizeof(float) * 3);
        
        t_face *face = modelf->faces[i];
        // printf("---------------1 | %d | %d\n", i, modelf->n_face);

        for (int j=0; j<face->n_verts; j++) {

            t_vect3f v = *modelv->verts[face->verts[j]];

            // screen_coords[j] = new_vect3i((v->x + 1.) * (float)par->width / 2., 
            //                                 (v->y + 1.) * (float)par->height / 2., 
            //                                 (v->z + 1.) * (float)par->depth / 2.);

            // t_vect3f *v0 = modelv->verts[face->verts[j]];
            // t_vect3f *v1 = modelv->verts[face->verts[(j + 1) % face->n_verts]];

            // int x0 = (v0->x+1.0)*par->width/2.0;
            // int y0 = (v0->y+1.0)*par->height/2.0;
            // int x1 = (v1->x+1.0)*par->width/2.0;
            // int y1 = (v1->y+1.0)*par->height/2.0;

            // line(x0, y0, x1, y1, main_data, data_color);

            t_vect3f buff = m2v(matrix_mult(matrix_mult(matrix_mult(viewport, projection), 
                                                                    model_view), v2m(v)));
            screen_coords[j] = vect3f2vect3i(buff.x, buff.y, buff.z);
            world_coords[j] = v;
            intensity[j] = dotproduct_vect3f(normalize_vect3f(*modelvn->norms[face->norms[j]]), *light_dir);

            // free(v);
            // v = NULL;
        }

        // t_vect3f n = crossproduct_vect3f(vectadd_vect3f(world_coords[2], negative_vect3f(world_coords[0])), 
        //                                 vectadd_vect3f(world_coords[1], negative_vect3f(world_coords[0])));
        
        // n = normalize_vect3f(n);

        // float intensity = dotproduct_vect3f(n, (*light_dir));

        // if (intensity > 0) {
        //     // t_vect2i *uv;
        //     // uv = (t_vect2i*)malloc(sizeof(t_vect2i) * 3);
        //     data_color[2] = (unsigned char)255 * intensity;
        //     data_color[1] = (unsigned char)255 * intensity;
        //     data_color[0] = (unsigned char)255 * intensity;
        //     triangle(screen_coords[0], screen_coords[1], screen_coords[2], main_data, data_color);
        // }

        triangle(screen_coords, intensity, main_data, data_color);

        // free(face);
        // face = NULL;
        

        // printf("---------------2 | %d | %d\n", i, modelf->n_face);

    }

    printf("---------------2\n");
    
    free(screen_coords);
    screen_coords = NULL;
    free(world_coords);
    world_coords = NULL;
    free(intensity);
    intensity = NULL;
    printf("---------------3\n");
}

void createImage(t_main *main_data)
{
    char* imageFileName = "bitmapImage.bmp";
    unsigned char *data_color;

    data_color = (unsigned char*)malloc(sizeof(unsigned char) * bytesPerPixel);

    // int y,x;

    printf("createImage();\n");
    // t_par *par = main_data->par;
    // for(y=0; y<par->height; y++){
    //     for(x=0; x<par->width; x++){
    //         int i = 0;    
    //         while (i < bytesPerPixel)
    //         {
                data_color[2] = (unsigned char)255;
                data_color[1] = (unsigned char)255;
                data_color[0] = (unsigned char)255;
                // data_color[2] = (unsigned char)((double)y/main_data->par->height*255); ///red
                // data_color[1] = (unsigned char)((double)x/main_data->par->width*255); ///green
                // data_color[0] = (unsigned char)(((double)y+x)/(main_data->par->height+main_data->par->width)*255); ///blue
    //             i++;
    //         }
    //         ft_memcpy(main_data->data+(x+y*par->width)*bytesPerPixel, data_color, bytesPerPixel);
    //     }
    // }

    // t_par *par;
    // t_f *modelf;
    // t_v *modelv;
    // t_vn *modelvn;
    // t_vt *modelvt;
    // par = main_data->par;
    // modelf = main_data->f;
    // modelv = main_data->v;
    // modelvn = main_data->vn;
    // modelvt = main_data->vt;

    // t_vect3f light_dir_buff;
    // t_vect3f *light_dir;
    // t_vect3f *camera_dir;
    // t_vect3f *eye;
    // t_vect3f *center;
    // light_dir_buff = normalize_vect3f(*new_vect3f(1, -1, 1));
    // light_dir = &light_dir_buff;
    // camera_dir = new_vect3f(0, 0, 3);
    // eye = new_vect3f(1, 1, 3);
    // center = new_vect3f(0, 0, 0);


    // t_matrix model_view;
    // t_matrix projection;
    // t_matrix viewport;
    // model_view = lookat(*eye, *center, *new_vect3f(0,1,0));
    // projection = identity(4);
    // viewport = new_viewport(par->width / 8, par->height / 8, 
    //                                 par->width * 3 / 4, par->height * 3 / 4);
    // projection.mat[3][2] = -1.f / magnitude_vect3f(vectadd_vect3f(*eye, negative_vect3f(*center)));
    // t_matrix z = matrix_mult(matrix_mult(viewport, projection), model_view);

    // t_vect3i *screen_coords;
    // t_vect3f *world_coords;
    // float *intensity;
    // screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * 3);
    // world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * 3);
    // intensity = (float*)malloc(sizeof(float) * 3);

    // printf("---------------1 | %d\n", modelf->n_face);
    // for (int i=0; i < modelf->n_face; i++) {
    // // for (int i=0; i < 3; i++) {

    //     // t_vect3i *screen_coords;
    //     // screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * 3);
    //     // t_vect3f *world_coords;
    //     // world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * 3);
    //     // float *intensity;
    //     // intensity = (float*)malloc(sizeof(float) * 3);
        
    //     t_face *face = modelf->faces[i];
    //     // printf("---------------1 | %d | %d\n", i, modelf->n_face);

    //     for (int j=0; j<face->n_verts; j++) {

    //         t_vect3f v = *modelv->verts[face->verts[j]];

    //         // screen_coords[j] = new_vect3i((v->x + 1.) * (float)par->width / 2., 
    //         //                                 (v->y + 1.) * (float)par->height / 2., 
    //         //                                 (v->z + 1.) * (float)par->depth / 2.);

    //         // t_vect3f *v0 = modelv->verts[face->verts[j]];
    //         // t_vect3f *v1 = modelv->verts[face->verts[(j + 1) % face->n_verts]];

    //         // int x0 = (v0->x+1.0)*par->width/2.0;
    //         // int y0 = (v0->y+1.0)*par->height/2.0;
    //         // int x1 = (v1->x+1.0)*par->width/2.0;
    //         // int y1 = (v1->y+1.0)*par->height/2.0;

    //         // line(x0, y0, x1, y1, main_data, data_color);

    //         t_vect3f buff = m2v(matrix_mult(matrix_mult(matrix_mult(viewport, projection), 
    //                                                                 model_view), v2m(v)));
    //         screen_coords[j] = vect3f2vect3i(buff.x, buff.y, buff.z);
    //         world_coords[j] = v;
    //         intensity[j] = dotproduct_vect3f(normalize_vect3f(*modelvn->norms[face->norms[j]]), *light_dir);

    //         // free(v);
    //         // v = NULL;
    //     }

    //     // t_vect3f n = crossproduct_vect3f(vectadd_vect3f(world_coords[2], negative_vect3f(world_coords[0])), 
    //     //                                 vectadd_vect3f(world_coords[1], negative_vect3f(world_coords[0])));
        
    //     // n = normalize_vect3f(n);

    //     // float intensity = dotproduct_vect3f(n, (*light_dir));

    //     // if (intensity > 0) {
    //     //     // t_vect2i *uv;
    //     //     // uv = (t_vect2i*)malloc(sizeof(t_vect2i) * 3);
    //     //     data_color[2] = (unsigned char)255 * intensity;
    //     //     data_color[1] = (unsigned char)255 * intensity;
    //     //     data_color[0] = (unsigned char)255 * intensity;
    //     //     triangle(screen_coords[0], screen_coords[1], screen_coords[2], main_data, data_color);
    //     // }

    //     triangle(screen_coords, intensity, main_data, data_color);

    //     // free(face);
    //     // face = NULL;
        

    //     // printf("---------------2 | %d | %d\n", i, modelf->n_face);

    // }

    // printf("---------------2\n");
    
    // free(screen_coords);
    // screen_coords = NULL;
    // free(world_coords);
    // world_coords = NULL;
    // free(intensity);
    // intensity = NULL;
    // printf("---------------3\n");

    if (main_data->vn->n_norms > 0)
    {
        normals_yes(main_data, data_color);
    }
    else
    {
        printf("createImage(); normals_no\n");
        normals_no(main_data, data_color);
    }
    

    generateBitmapImage(main_data->data, main_data->par->height, main_data->par->width, imageFileName);
    printf("Image generated!!\n");
}