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



t_main      *init_data(int width, int height) {
    t_main  *data;
    int i;

    if ((data = (t_main*)malloc(sizeof(t_main))) == NULL) {
        printf("%s\n", "false malloc");
    }
    data->data = (unsigned char*)malloc(sizeof(unsigned char) * (height * width * bytesPerPixel));
    data->v = (t_v*)malloc(sizeof(t_v));
    data->f = (t_f*)malloc(sizeof(t_f));
    data->par = (t_par*)malloc(sizeof(t_par));
    data->par->height = height;
    data->par->width = width;
    data->par->depth  = 255;
    data->zbuff = (int*)malloc(sizeof(int) * (height * width));
    i = 0;
    while (i < (height * width))
    {
        data->zbuff[i] = -2147483648;
        i++;
    }
    return (data);
}

int main(int argc, char** argv) 
{
    t_main  *main_data;

    printf("%s\n", "--------------- Start   program ---------------");
    main_data = init_data(800, 800);
    parser(argv[1], main_data);
    createImage(main_data);
    printf("%s\n", "--------------- End     program ---------------");
    return 0;
}