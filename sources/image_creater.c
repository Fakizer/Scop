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

    if (data_color[0] == 0 && data_color[1] == 0 && data_color[2] == 0)
    {
        if (x < width && x > 300)
        {
            if (y < height && y > 300)
                printf("9 ebal\n");
        }
    }
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

void    triangle(t_vect3i t0, t_vect3i t1, t_vect3i t2, t_main *main_data, unsigned char *data_color)
{
    if (t0.y==t1.y && t0.y==t2.y) 
        return;
    if (t0.y>t1.y) 
        swap_vect3i(&t0, &t1);
    if (t0.y>t2.y) 
        swap_vect3i(&t0, &t2);
    if (t1.y>t2.y) 
        swap_vect3i(&t1, &t2);
    
    int total_height = t2.y-t0.y;

    int i = 0;
    int second_half = 0;
    int segment_height = 0;
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
        t_vect3i A = new_vect3i(A_f.x, A_f.y, A_f.z);

        t_vect3f B_buff1_f = vectadd_vect3f(t1_f, vectmult_vect3f(vectadd_vect3f(t2_f, negative_vect3f(t1_f)), beta));
        t_vect3i B_buff1 = new_vect3i(B_buff1_f.x, B_buff1_f.y, B_buff1_f.z);

        t_vect3f B_buff2_f = vectadd_vect3f(t0_f, vectmult_vect3f(vectadd_vect3f(t1_f, negative_vect3f(t0_f)), beta));
        t_vect3i B_buff2 = new_vect3i(B_buff2_f.x, B_buff2_f.y, B_buff2_f.z);


        t_vect3i B = second_half == 1 ? B_buff1 : B_buff2;


        if (A.x > B.x)
            swap_vect3i(&A, &B);

        int j = A.x;

        // printf("--------------------41================================= | %d\n", i);
        while(j <= B.x)
        {
            float phi = B.x == A.x ? 1. : (float)(j - A.x) / (float)(B.x - A.x);
            t_vect3f A_f = copy_vect3f(A.x, A.y, A.z);
            t_vect3f B_f = copy_vect3f(B.x, B.y, B.z);
            t_vect3f P_buff = vectadd_vect3f(A_f, vectmult_vect3f(vectadd_vect3f(B_f, negative_vect3f(A_f)), phi));
            t_vect3i P = new_vect3i(P_buff.x, P_buff.y, P_buff.z);
            int idx = P.x + P.y * main_data->par->width;
            // if (idx < main_data->par->width * main_data->par->height)
            // {
                // printf("bleatb\n");
                // printf("--------------------42================================= | %d | %d | %d\n\n", i, j, idx);
                if (main_data->zbuff[idx] < P.z)
                {
                    main_data->zbuff[idx] = P.z;
                    setter(P.x, P.y, main_data, data_color);
                    // setter(j, t0.y + i, main_data, data_color);
                }
            // }
            j++;
        }

        // printf("--------------------43================================= | %d\n\n", i);
        i++;
    }
}

void createImage(t_main *main_data)
{
    char* imageFileName = "bitmapImage.bmp";
    unsigned char *data_color;

    data_color = (unsigned char*)malloc(sizeof(unsigned char) * bytesPerPixel);

    int y,x;

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

    t_par *par = main_data->par;
    t_f *modelf = main_data->f;
    t_v *modelv = main_data->v;

    t_vect3f *light_dir = new_vect3f(0, 0, -1);

    printf("---------------1 | %d\n", modelf->n_face);
    for (int i=0; i < modelf->n_face; i++) {
        t_face *face = modelf->faces[i];
        printf("---------------1 | %d | %d\n", i, modelf->n_face);
        t_vect3i *screen_coords;
        screen_coords = (t_vect3i*)malloc(sizeof(t_vect3i) * face->n_verts);
        t_vect3f *world_coords;
        world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * face->n_verts);


        for (int j=0; j<face->n_verts; j++) {

            t_vect3f *v = modelv->verts[face->verts[j]];

            screen_coords[j] = new_vect3i((v->x + 1.) * (float)par->width / 2., 
                                            (v->y + 1.) * (float)par->height / 2., 
                                            (v->z + 1.) * (float)par->depth / 2.);
            world_coords[j] = (*v);

            // t_vect3f *v0 = modelv->verts[face->verts[j]];
            // t_vect3f *v1 = modelv->verts[face->verts[(j + 1) % face->n_verts]];

            // int x0 = (v0->x+1.0)*par->width/2.0;
            // int y0 = (v0->y+1.0)*par->height/2.0;
            // int x1 = (v1->x+1.0)*par->width/2.0;
            // int y1 = (v1->y+1.0)*par->height/2.0;

            // line(x0, y0, x1, y1, main_data, data_color);
        }

        t_vect3f n = crossproduct_vect3f(vectadd_vect3f(world_coords[2], negative_vect3f(world_coords[0])), 
                                        vectadd_vect3f(world_coords[1], negative_vect3f(world_coords[0])));
        
        n = normalize_vect3f(n);

        float intensity = dotproduct_vect3f(n, (*light_dir));

        if (intensity > 0) {
            // t_vect2i *uv;
            // uv = (t_vect2i*)malloc(sizeof(t_vect2i) * 3);
            data_color[2] = (unsigned char)255 * intensity;
            data_color[1] = (unsigned char)255 * intensity;
            data_color[0] = (unsigned char)255 * intensity;
            triangle(screen_coords[0], screen_coords[1], screen_coords[2], main_data, data_color);
        }

    }
    
    printf("---------------2\n");

    generateBitmapImage(main_data->data, par->height, par->width, imageFileName);
    printf("Image generated!!\n");
}