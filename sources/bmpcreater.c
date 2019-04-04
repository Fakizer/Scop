#include "scop.h"

void    setter(int x, int y, t_main *main_data, unsigned char *data_color)
{
    int width = main_data->par->width;
    int height = main_data->par->height;

    if (!main_data->data || x<0 || y<0 || x>=width || y>=height) {
		return ;
	}
    ft_memcpy(main_data->data+(x+y*width)*bytesPerPixel, data_color, bytesPerPixel);
}

void    line(int x0, int y0, int x1, int y1, t_main *main_data, unsigned char *data_color)
{
    int steep = 0;
    if (abs(x0-x1)<abs(y0-y1)) {
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
    if (x0>x1) {
        int y = x0;
        x0 = x1;
        x1 = y;
        // swap(x0, x1);
        y = y0;
        y0 = y1;
        y1 = y;
        // swap(y0, y1);
    }

    for (int x=x0; x<=x1; x++) {
        float t = (x-x0)/(float)(x1-x0);
        int y = y0*(1.-t) + y1*t;
        if (steep == 1) {
            setter(y, x, main_data, data_color);
        } else {
            setter(x, y, main_data, data_color);
        }
    }
}

void createImage(t_main *main_data)
{
    char* imageFileName = "bitmapImage.bmp";
    unsigned char *data_color;

    data_color = (unsigned char*)malloc(sizeof(unsigned char) * bytesPerPixel);

    int y,x;
    // for(y=0; y<height; y++){
    //     for(x=0; x<width; x++){
            int i = 0;    
            while (i < bytesPerPixel)
            {
                data_color[2] = (unsigned char)255;
                data_color[1] = (unsigned char)255;
                data_color[0] = (unsigned char)255;
                // data_color[2] = (unsigned char)((double)y/main_data->par->height*255); ///red
                // data_color[1] = (unsigned char)((double)x/main_data->par->width*255); ///green
                // data_color[0] = (unsigned char)(((double)y+x)/(main_data->par->height+main_data->par->width)*255); ///blue
                i++;
            }
    //         ft_memcpy(data+(x+y*width)*bytesPerPixel, data_c, bytesPerPixel);
    //     }
    // }

    t_par *par = main_data->par;
    t_f *f = main_data->f;
    t_v *v = main_data->v;
    t_face *qwe = f->faces[i];
    for (int i=0; i < f->n_face; i++) {
        t_face *face = f->faces[i];
        // printf("---------------1 | %d | %d\n", f->n_face, i);
        // printf("---------------1 | %d\n", face->n_verts);
        // printf("---------------1\n");
        for (int j=0; j<face->n_verts; j++) {

            // printf("---------------11\n");
            // printf("---------------11 | %d | %d | %d | %d\n", f->n_face, i, face->n_verts, j);

            t_vert *v0 = v->verts[face->verts[j]];
            t_vert *v1 = v->verts[face->verts[(j + 1) % face->n_verts]];

            int x0 = (v0->dots[0]+1.)*par->width/2.;
            int y0 = (v0->dots[1]+1.)*par->height/2.;
            int x1 = (v1->dots[0]+1.)*par->width/2.;
            int y1 = (v1->dots[1]+1.)*par->height/2.;
            
            line(x0, y0, x1, y1, main_data, data_color);

            // printf("---------------12 | %d | %d | %d | %d\n", f->n_face, i, face->n_verts, j);
        }
    }
    
    printf("---------------2\n");

    generateBitmapImage(main_data->data, par->height, par->width, imageFileName);
    printf("Image generated!!\n");
}

void generateBitmapImage(unsigned char *image, int height, int width, char* imageFileName){

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (width*bytesPerPixel) % 4) % 4;

    unsigned char* fileHeader = createBitmapFileHeader(height, width, paddingSize);
    unsigned char* infoHeader = createBitmapInfoHeader(height, width);

    FILE* imageFile = fopen(imageFileName, "wb");

    fwrite(fileHeader, 1, fileHeaderSize, imageFile);
    fwrite(infoHeader, 1, infoHeaderSize, imageFile);

    int i;
    for(i=0; i<height; i++){
        fwrite(image+(i*width*bytesPerPixel), bytesPerPixel, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
    // free(fileHeader);
    // free(infoHeader);
}

unsigned char* createBitmapFileHeader(int height, int width, int paddingSize){
    int fileSize = fileHeaderSize + infoHeaderSize + (bytesPerPixel*width+paddingSize) * height;

    static unsigned char fileHeader[] = {
        0,0, /// signature
        0,0,0,0, /// image file size in bytes
        0,0,0,0, /// reserved
        0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize    );
    fileHeader[ 3] = (unsigned char)(fileSize>> 8);
    fileHeader[ 4] = (unsigned char)(fileSize>>16);
    fileHeader[ 5] = (unsigned char)(fileSize>>24);
    fileHeader[10] = (unsigned char)(fileHeaderSize + infoHeaderSize);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader(int height, int width){
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size
        0,0,0,0, /// image width
        0,0,0,0, /// image height
        0,0, /// number of color planes
        0,0, /// bits per pixel
        0,0,0,0, /// compression
        0,0,0,0, /// image size
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(infoHeaderSize);
    infoHeader[ 4] = (unsigned char)(width    );
    infoHeader[ 5] = (unsigned char)(width>> 8);
    infoHeader[ 6] = (unsigned char)(width>>16);
    infoHeader[ 7] = (unsigned char)(width>>24);
    infoHeader[ 8] = (unsigned char)(height    );
    infoHeader[ 9] = (unsigned char)(height>> 8);
    infoHeader[10] = (unsigned char)(height>>16);
    infoHeader[11] = (unsigned char)(height>>24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(bytesPerPixel*8);

    return infoHeader;
}