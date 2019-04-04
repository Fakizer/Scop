#include "scop.h"

void    setter(int x, int y, t_main *main_data, unsigned char *data_color)
{
    int width = 1920;
    int height = 1080;

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
        if (steep) {
            setter(y, x, main_data, data_color);
        } else {
            setter(x, y, main_data, data_color);
        }
    }
}

void createImage(int my_width, int my_height, t_main *main_data) {
    int height = my_height;
    int width = my_width;
    char* imageFileName = "bitmapImage.bmp";

    unsigned char *data;
    unsigned char *data_color;

    data_color = (unsigned char*)malloc(sizeof(unsigned char) * bytesPerPixel);
    data = (unsigned char*)malloc(sizeof(unsigned char) * (height * width * bytesPerPixel));

    main_data->data = data;
    int y,x;
    // for(y=0; y<height; y++){
    //     for(x=0; x<width; x++){
            int i = 0;    
            while (i < bytesPerPixel)
            {
                data_color[2] = (unsigned char)((double)y/height*255); ///red
                data_color[1] = (unsigned char)((double)x/width*255); ///green
                data_color[0] = (unsigned char)(((double)y+x)/(height+width)*255); ///blue
                i++;
            }
    //         ft_memcpy(data+(x+y*width)*bytesPerPixel, data_c, bytesPerPixel);
    //     }
    // }

    for (int i=0; i<main_data->n_face; i++) {
        t_f face = main_data->f[i];
        printf("---------------1\n");
        for (int j=0; j<face.n_verts; j++) {

            t_v v0 = main_data->v[face.verts[j]];
            t_v v1 = main_data->v[face.verts[(j + 1) % face.n_verts]];
            printf("%f   ->  main_data->v[face.verts[j]].dots[0]\n", main_data->v[face.verts[j]].dots[0]);
            printf("%d   ->  face.verts[(j + 1) %% face.n_verts]\n", face.verts[(j + 1) % face.n_verts]);
            printf("%f\n", v0.dots[0]);
            printf("---------------2\n");
            int x0 = (v0.dots[0]+1.)*width/2.;
            int y0 = (v0.dots[1]+1.)*height/2.;
            int x1 = (v1.dots[0]+1.)*width/2.;
            printf("---------------3\n");
            int y1 = (v1.dots[1]+1.)*height/2.;
            

            line(x0, y0, x1, y1, main_data, data_color);
        }
    }

    generateBitmapImage(data, height, width, imageFileName);
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