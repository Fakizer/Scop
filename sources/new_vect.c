#include "scop.h"

t_vect2f        new_vect2f(float x, float y)
{
    t_vect2f vect;

    vect.x = x; 
    vect.y = y;
    return vect;
}

t_vect2i        new_vect2i(int x, int y)
{
    t_vect2i vect;

    vect.x = x; 
    vect.y = y;
    return vect;
}

t_vect3f        *new_vect3f(float x, float y, float z)
{
    t_vect3f *vect;

    vect = (t_vect3f*)malloc(sizeof(t_vect3f));
    vect->x = x; 
    vect->y = y;
    vect->z = z;
    return vect;
}

t_vect3i        new_vect3i(int x, int y, int z)
{
    t_vect3i vect;

    vect.x = x; 
    vect.y = y;
    vect.z = z;
    return vect;
}
