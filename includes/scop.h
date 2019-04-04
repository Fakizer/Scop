/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:18:00 by vvlasenk          #+#    #+#             */
/*   Updated: 2019/03/28 14:24:30 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct  s_face
{
    int         n_verts;
    int         *face;
}               t_face;


typedef struct  s_f
{
    t_face      **faces;
    int         n_face;
}               t_f;

typedef struct  s_vert
{
    int         n_dots;
    int         *vert;
}               t_vert;

typedef struct  s_v
{
    int         n_vert;
    t_vert       **verts;
}               t_v;

typedef struct  s_main
{
    unsigned char *data;
    t_v         *v;
    t_f         *f;
}               t_main;


extern const int bytesPerPixel; /// red, green, blue
extern const int fileHeaderSize;
extern const int infoHeaderSize;

void            createImage(int my_width, int my_height, t_main *data);
void            generateBitmapImage(unsigned char *image, int height, int width, char* imageFileName);
unsigned char*  createBitmapFileHeader(int height, int width, int paddingSize);
unsigned char*  createBitmapInfoHeader(int height, int width);

#endif