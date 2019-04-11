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
# include "vect.h"

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
    int         *verts;
}               t_face;

typedef struct  s_f
{
    int         n_face;
    t_face      **faces;
}               t_f;

// typedef struct  s_vert
// {
//     int         n_dots;
//     float       *dots;
// }               t_vert;

typedef struct  s_v
{
    int         n_vert;
    t_vect3f    **verts;
}               t_v;

typedef struct  s_par
{
    int         width;
    int         height;
    int         depth;
}               t_par;


typedef struct  s_main
{
    unsigned char *data;
    t_par       *par;
    t_v         *v;
    t_f         *f;
    int         *zbuff;
}               t_main;


extern const int bytesPerPixel; /// red, green, blue
extern const int fileHeaderSize;
extern const int infoHeaderSize;

/*image_creater.c*/
void            createImage(t_main *data);
void            line(int x0, int y0, int x1, int y1, t_main *main_data, unsigned char *data_color);
void            setter(int x, int y, t_main *main_data, unsigned char *data_color);


/*bmpcreater.c*/
void            generateBitmapImage(unsigned char *image, int height, int width, char* imageFileName);
unsigned char*  createBitmapFileHeader(int height, int width, int paddingSize);
unsigned char*  createBitmapInfoHeader(int height, int width);

/*parser.c*/
void    parser(char *filename, t_main  *main_data);
int     counter(char *filename, char *flag);
void    set_data_v(char *filename, char *flag, t_v *v);
void    set_data_f(char *filename, char *flag, t_f *f);

/*math.c*/
t_vect3f		negative_vect3f(t_vect3f vect);
t_vect3f		vectmult_vect3f(t_vect3f vect, float scalar);
t_vect3f		vectadd_vect3f(t_vect3f vect, t_vect3f v);
t_vect3f		crossproduct_vect3f(t_vect3f vect, t_vect3f v);
t_vect3f		normalize_vect3f(t_vect3f vect);
float	    	magnitude_vect3f(t_vect3f vect);
float		    dotproduct_vect3f(t_vect3f ray, t_vect3f normal);

t_vect2i		negative_vect2i(t_vect2i vect);
t_vect2i		vectadd_vect2i(t_vect2i vect, t_vect2i v);
t_vect2i		vectmult_vect2i(t_vect2i vect, float scalar);

t_vect3i		negative_vect3i(t_vect3i vect);
t_vect3i		vectadd_vect3i(t_vect3i vect, t_vect3i v);
t_vect3i		vectmult_vect3i(t_vect3i vect, float scalar);


#endif