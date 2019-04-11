#include "scop.h"
# include <math.h>


t_vect3f		negative_vect3f(t_vect3f vect)
{
	t_vect3f vcopy;

	vcopy.x = -vect.x;
	vcopy.y = -vect.y;
	vcopy.z = -vect.z;
	return (vcopy);
}

t_vect3f		vectmult_vect3f(t_vect3f vect, float scalar)
{
	t_vect3f vcopy;

	vcopy.x = vect.x * scalar;
	vcopy.y = vect.y * scalar;
	vcopy.z = vect.z * scalar;
	return (vcopy);
}

t_vect3f		vectadd_vect3f(t_vect3f vect, t_vect3f v)
{
	t_vect3f	vcopy;

	vcopy.x = vect.x + v.x;
	vcopy.y = vect.y + v.y;
	vcopy.z = vect.z + v.z;
	return (vcopy);
}

t_vect3f		crossproduct_vect3f(t_vect3f vect, t_vect3f v)
{
	t_vect3f vcopy;

	vcopy.x = vect.y * v.z - vect.z * v.y;
	vcopy.y = vect.z * v.x - vect.x * v.z;
	vcopy.z = vect.x * v.y - vect.y * v.x;
	return (vcopy);
}

t_vect3f		normalize_vect3f(t_vect3f vect)
{
	float magn;
	t_vect3f vcopy;

	magn = magnitude_vect3f(vect);
	vcopy.x = vect.x / magn;
	vcopy.y = vect.y / magn;
	vcopy.z = vect.z / magn;
	return (vcopy);
}

float		magnitude_vect3f(t_vect3f vect)
{
	return (sqrtf((vect.x * vect.x) + (vect.y * vect.y) +
		(vect.z * vect.z)));
}

float		dotproduct_vect3f(t_vect3f ray, t_vect3f normal)
{
	return (ray.x * normal.x + ray.y * normal.y + ray.z * normal.z);
}

/*vect2i*/

t_vect2i		negative_vect2i(t_vect2i vect)
{
	t_vect2i vcopy;

	vcopy.x = -vect.x;
	vcopy.y = -vect.y;
	return (vcopy);
}

t_vect2i		vectadd_vect2i(t_vect2i vect, t_vect2i v)
{
	t_vect2i	vcopy;

	vcopy.x = vect.x + v.x;
	vcopy.y = vect.y + v.y;
	return (vcopy);
}

t_vect2i		vectmult_vect2i(t_vect2i vect, float scalar)
{
	t_vect2i vcopy;

	vcopy.x = vect.x * scalar;
	vcopy.y = vect.y * scalar;
	return (vcopy);
}

/*vect3i*/

t_vect3i		negative_vect3i(t_vect3i vect)
{
	t_vect3i vcopy;

	vcopy.x = -vect.x;
	vcopy.y = -vect.y;
	vcopy.z = -vect.z;
	return (vcopy);
}

t_vect3i		vectadd_vect3i(t_vect3i vect, t_vect3i v)
{
	t_vect3i	vcopy;

	vcopy.x = vect.x + v.x;
	vcopy.y = vect.y + v.y;
	vcopy.z = vect.z + v.z;
	return (vcopy);
}

t_vect3i		vectmult_vect3i(t_vect3i vect, float scalar)
{
	t_vect3i vcopy;

	vcopy.x = vect.x * scalar;
	vcopy.y = vect.y * scalar;
	vcopy.z = vect.z * scalar;
	return (vcopy);
}
