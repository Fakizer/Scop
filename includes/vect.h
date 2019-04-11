#ifndef VECT_H
# define VECT_H

typedef struct				s_vect2i
{
	int	    				x;
	int	    				y;
}							t_vect2i;

typedef struct				s_vect2f
{
	float					x;
	float					y;
}							t_vect2f;

typedef struct				s_vect3i
{
	int 					x;
	int 					y;
	int 					z;
}							t_vect3i;

typedef struct				s_vect3f
{
	float					x;
	float					y;
	float					z;
}							t_vect3f;

t_vect2f        new_vect2f(float x, float y);
t_vect2i        new_vect2i(int x, int y);
t_vect3f        *new_vect3f(float x, float y, float z);
t_vect3f        copy_vect3f(float x, float y, float z);
t_vect3i        new_vect3i(int x, int y, int z);


#endif