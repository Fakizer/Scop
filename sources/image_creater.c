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
        // if (x < width && x > 300)
        // {
        //     if (y < height && y > 300)
                printf("9 ebal\n");
        // }
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

void    swap_vect2i(t_vect2i *t1, t_vect2i *t2)
{
    t_vect2i buff;

    buff = *t1;
    *t1 = *t2;
    *t2 = buff;
}

void    triangle(t_vect2i t0, t_vect2i t1, t_vect2i t2, t_main *main_data, unsigned char *data_color)
{
    if (t0.y==t1.y && t0.y==t2.y) 
        return;
    if (t0.y>t1.y) 
        swap_vect2i(&t0, &t1);
    if (t0.y>t2.y) 
        swap_vect2i(&t0, &t2);
    if (t1.y>t2.y) 
        swap_vect2i(&t1, &t2);
    
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
        
        t_vect2i A = vectadd_vect2i(t0, vectmult_vect2i(vectadd_vect2i(t2, negative_vect2i(t0)), alpha));
        t_vect2i B_buff1 = vectadd_vect2i(t1, vectmult_vect2i(vectadd_vect2i(t2, negative_vect2i(t1)), beta));
        t_vect2i B_buff2 = vectadd_vect2i(t0, vectmult_vect2i(vectadd_vect2i(t1, negative_vect2i(t0)), beta));

        t_vect2i B = second_half == 1 ? B_buff1 : B_buff2;

        if (A.x > B.x) {
            printf("first------------A.x: %d | A.y: %d\n", A.x, A.y);
            printf("first------------B.x: %d | B.y: %d\n", B.x, B.y);
            printf("--------------------------------\n");

            swap_vect2i(&A, &B);

            printf("second------------A.x: %d | A.y: %d\n", A.x, A.y);
            printf("second------------B.x: %d | B.y: %d\n\n", B.x, B.y);
        }
        int j = A.x;
        while(j <= B.x)
        {
            setter(j, t0.y + i, main_data, data_color);
            j++;
        }

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

        t_vect2i *screen_coords;
        screen_coords = (t_vect2i*)malloc(sizeof(t_vect2i) * face->n_verts);
        t_vect3f *world_coords;
        world_coords = (t_vect3f*)malloc(sizeof(t_vect3f) * face->n_verts);

        for (int j=0; j<face->n_verts; j++) {

            t_vect3f *v = modelv->verts[face->verts[j]];

            screen_coords[j] = new_vect2i((v->x + 1.) * par->width/2., 
                                            (v->y + 1.) * par->height/2.);
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
        
        // printf("%f | %f | %f\n", n.x, n.y, n.z);
        n = normalize_vect3f(n);
        // printf("%f | %f | %f\n", n.x, n.y, n.z);

        float intensity = dotproduct_vect3f(n, (*light_dir));

        // printf("-------| %f |-------\n\n", intensity);

        if (intensity > 0) {
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